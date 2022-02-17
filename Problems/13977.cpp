#include <iostream>
#include <utility>
using namespace std;
using ll = long long;
constexpr ll M = 1000000007;
ll power(ll a, ll n) {
	if (!n) return 1;
	if (n == 1) return a;
	auto const r = power(a, n >> 1);
	return (((r * r) % M) * power(a, n & 1)) % M;
}
inline ll inverse(ll n) { return power(n, M - 2); }
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int m; cin >> m;
	auto a = new pair<int, int>[m];
	ll mx = 0;
	for (int i = 0; i < m; i++) {
		cin >> a[i].first >> a[i].second;
		if (mx < a[i].first) mx = a[i].first;
	}
	auto mul = new ll[mx + 1]; mul[0] = 1;
	for (ll i = 1; i <= mx; i++) {
		mul[i] = (mul[i - 1] * i) % M;
	}
	for (int i = 0; i < m; i++) {
		cout << (((mul[a[i].first] * inverse(mul[a[i].second])) % M) * inverse(mul[a[i].first - a[i].second])) % M << '\n';
	}
}