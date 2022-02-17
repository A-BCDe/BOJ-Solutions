#include <algorithm>
#include <stdio.h>
using ll = long long;
int main() {
	ll t, n, m;
	scanf("%lld%lld", &t, &n);
	auto a = new ll[n + 1]();
	auto asum = new ll[n * (n + 1) / 2];
	ll cnt = 0;
	for (ll i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
		a[i] += a[i - 1];
		for (ll j = 0; j < i; j++) {
			asum[cnt++] = a[i] - a[j];
		}
	}
	delete[] a;
	scanf("%lld", &m);
	a = new ll[m + 1]();
	auto bsum = new ll[m * (m + 1) / 2]();
	cnt = 0;
	for (ll i = 1; i <= m; i++) {
		scanf("%lld", &a[i]);
		a[i] += a[i - 1];
		for (ll j = 0; j < i; j++) {
			bsum[cnt++] = a[i] - a[j];
		}
	}
	delete[] a;
	std::sort(bsum, bsum + m * (m + 1) / 2);
	ll res = 0;
	for (ll i = 0; i < n * (n + 1) / 2; i++) {
		auto lo = std::lower_bound(bsum, bsum + m * (m + 1) / 2, t - asum[i]);
		auto hi = std::upper_bound(bsum, bsum + m * (m + 1) / 2, t - asum[i]);
		res += hi - lo;
	}
	printf("%lld", res);
	delete[] bsum;
	delete[] asum;
}