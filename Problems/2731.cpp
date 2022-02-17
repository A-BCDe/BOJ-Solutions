#include <stdio.h>
using ll = long long;
ll power(ll n, ll k) {
	if (k == 0) return 1;
	if (k == 1) return n;
	ll const r = power(n, k / 2);
	return r * r * power(n, k % 2);
}
ll mul(ll n, ll m, ll p) {
	ll res = 0;
	ll k = 1;
	ll slice = p;
	while (m) {
		res += ((((n % p) * (m % 10)) % (p / k)) * (k % p)) % p;
		res %= p;
		k *= 10;
		m /= 10;
	}
	return res;
}
ll three(ll n, ll m) {
	return mul(mul(n, n, m), n, m);
}
int main() {
	int tt;
	scanf("%d", &tt);
	while (tt--) {
		ll n;
		scanf("%lld", &n);
		ll k = 1;
		while (n >= power(10, k)) k++;
		ll const p = power(10, k);
		ll m;
		switch (n % 10) {
		case 1:
		case 9: m = n % 10; break;
		case 3:
		case 7: m = 10 - n % 10; break;	
		}
		for (ll i = 1; i < k; i++) {
			ll const mul = power(10, i);
			for (ll j = 0; j < 10; j++) {
				auto const x = three(mul * j + m, mul * 10);
				if (x == n % (mul * 10)) {
					m += mul * j;
					break;
				}
			}
		}
		printf("%lld\n", m);
	}
}