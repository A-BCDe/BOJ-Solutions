#include <stdio.h>
using ll = long long;
int main() {
	ll n, k;
	scanf("%lld%lld", &n, &k);
	ll l = 1, r = n * n + 1;
	ll res = 1;
	while (l < r) {
		ll const m = (l + r) / 2;
		ll sum = 0;
		for (int i = 1; i <= n; i++) {
			ll x = m / i;
			sum += (x > n ? n : x);
		}
		if (sum >= k) {
			res = m;
			r = m;
		}
		else l = m + 1;
	}
	printf("%lld", res);
}