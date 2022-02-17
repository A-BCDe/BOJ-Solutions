#include <algorithm>
#include <stdio.h>
int main() {
	int n;
	scanf("%d", &n);
	auto a = new int[n];
	int res = 2000000001;
	int res1 = -1, res2 = -1;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		//printf("%d %d %d\n", res, res1, res2);
		if (!i) continue;
		auto p = std::lower_bound(a, a + i, -a[i]);
		if (p == a + i) {
			if (p != a) {
				if (res > abs(*(p - 1) + a[i])) {
					res = abs(*(p - 1) + a[i]);
					res1 = *(p - 1);
					res2 = a[i];
				}
			}
			continue;
		}
		if (res > abs(*p + a[i])) {
			res = abs(*p + a[i]);
			res1 = *p;
			res2 = a[i];
		}
		if (p != a) {
			if (res > abs(*(p - 1) + a[i])) {
				res = abs(*(p - 1) + a[i]);
				res1 = *(p - 1);
				res2 = a[i];
			}
		}
	}
	printf("%d %d", res1, res2);
}