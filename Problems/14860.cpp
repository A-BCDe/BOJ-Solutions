#include <algorithm>
#include <stdio.h>
#include <vector>
using namespace std;
using ll = long long;
constexpr ll M = 1000000007;
ll power(ll a, ll n) {
	if (!n) return 1;
	if (n == 1) return a % M;
	auto const r = power(a, n / 2);
	return (((r * r) % M) * power(a, n % 2)) % M;
}
vector<ll> make_prime(ll n) {
	ll i = 2;
	vector<ll> v;
	auto visited = new bool[n + 1]();
	while (i * i <= n) {
		if (!visited[i]) {
			v.push_back(i);
			for (ll j = (i << 1); j <= n; j += i) {
				visited[j] = true;
			}
		}
		i++;
	}
	while (i <= n) {
		if (!visited[i]) v.push_back(i);
		i++;
	}
	delete[] visited;
	return v;
}
int main() {
	ll n, m;
	scanf("%lld%lld", &n, &m);
	auto prime = make_prime(min(n, m));
	ll res = 1;
	for (auto p : prime) {
		ll const x = p;
		ll sum = 0;
		while (p <= n && p <= m) {
			sum += (n / p) * (m / p);
			p *= x;
		}
		res = (res * power(x, sum)) % M;
	}
	printf("%lld", res);
}