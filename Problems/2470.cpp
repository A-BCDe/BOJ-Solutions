#include <algorithm>
#include <stdio.h>
using ll = long long;
int main() {
	int n;
	scanf("%d", &n);
	auto a = new ll[n];
	for (int i = 0; i < n; i++) scanf("%lld", &a[i]);
	std::sort(a, a + n);
	int l = 0, r = n - 1;
	int resl = 0, resr = n - 1;
	ll res = 2000000000;
	while (l < r) {
		auto const x = a[l] + a[r];
		if (!x) {
			printf("%lld %lld", a[l], a[r]);
			return 0;
		}
		if (res > std::abs(x)) {
			res = std::abs(x);
			resl = l, resr = r;
		}
		if (x < 0) l++;
		else r--;
	}
	printf("%lld %lld", a[resl], a[resr]);
}