#include <iostream>
using ll = long long;
constexpr ll p = 1000000007;
using namespace std;
ll power(ll n, ll m) {
	if (m == 0) return 1;
	if (m == 1) return n;
	auto const r = power(n, m / 2);
	return (((r * r) % p) * power(n, m % 2)) % p;
}
int main() {
	ll n, k;
	cin >> n >> k;
	ll res = 1, inv = 1;
	for (ll i = 1; i <= n; i++) {
		res = (res * i) % p;
	}
	for (ll i = 1; i <= k; i++) {
		inv = (inv * i) % p;
	}
	for (ll i = 1; i <= n - k; i++) {
		inv = (inv * i) % p;
	}
	inv = power(inv, p - 2);
	cout << (res * inv) % p;
}