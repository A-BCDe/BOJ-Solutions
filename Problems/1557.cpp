#include <stdio.h>
using ll = long long;
ll f(ll* mobius, ll n) {
	ll res = 0;
	for (ll i = 1; i * i <= n; i++) {
		res += mobius[i] * (n / (i * i));
	}
	return res;
}
int main() {
	auto mobius = new ll[1000001]();
	mobius[1] = 1;
	for (int i = 1; i <= 1000000; i++) {
		for (int j = (i << 1); j <= 1000000; j += i) {
			mobius[j] -= mobius[i];
		}
	}
	ll n;
	scanf("%lld", &n);
	ll l = 1, r = 2;
	while (f(mobius, r) <= n) l <<= 1, r <<= 1;
	while (l < r) {
		auto const m = (l + r) / 2;
		if (f(mobius, m) < n) {
			l = m + 1;
		}
		else {
			r = m;
		}
	}
	printf("%lld", l);
}