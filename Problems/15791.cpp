#include <stdio.h>
using ll = unsigned long long;
constexpr ll M = 1000000007;
ll power(ll a, ll n) {
	if (!n) return 1;
	if (n == 1) return a;
	auto const r = power(a, n >> 1);
	return (((r * r) % M) * power(a, n & 1)) % M;
}
inline ll inverse(ll inv) { return power(inv, M - 2); }
int main() {
	ll n, m;
	scanf("%llu%llu", &n, &m);
	ll mul = 1, inv = 1;
	for (ll i = 1; i <= n; i++) mul = (mul * i) % M;
	for (ll i = 1; i <= m; i++) inv = (inv * i) % M;
	for (ll i = 1; i <= n - m; i++) inv = (inv * i) % M;
	printf("%llu", (mul * inverse(inv)) % M);
}