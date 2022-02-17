#include <numeric>
#include <stdio.h>
using ll = __uint128_t;
ll power(ll a, ll n) {
	if (!n) return 1;
	if (n == 1) return a;
	ll const r = power(a, n >> 1);
	return r * r * power(a, n & 1);
}
ll power(ll a, ll n, ll m) {
	if (!n) return 1;
	if (n == 1) return a % m;
	ll const r = power(a, n >> 1, m);
	return (ll)(((r * r) % m) * power(a, n & 1, m)) % m;
}
int main() {
	unsigned long long n, a;
	scanf("%llu%llu", &n, &a);
	printf("%llu ", n - (a % n));
	ll g = std::gcd(n, a);
	if (g != 1) {
		printf("-1");
		return 0;
	}
	ll tn = n;
	ll phi = 1;
	for (ll i = 2; i * i <= tn; i++) {
		ll cnt = 0;
		while (tn % i == 0) {
			tn /= i;
			cnt++;
		}
		if (cnt) phi *= i * power(i - 1, cnt - 1);
	}
	if (tn > 1) phi = tn;
	printf("%llu", (unsigned long long)power(a, phi - 2, n));
}