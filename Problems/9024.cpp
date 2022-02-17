#include <stdio.h>
#include <algorithm>
long long _abs(long long a) { return a > 0 ? a : -a; }
int main() {
	int tt;
	scanf("%d", &tt);
	while (tt--) {
		int n, k;
		scanf("%d%d", &n, &k);
		auto a = new long long[n];
		for (int i = 0; i < n; i++) {
			scanf("%lld", &a[i]);
		}
		std::sort(a, a + n);
		int l = 0, r = n - 1;
		long long max = 1000000000;
		int cnt = 0;
		while (l < r) {
			long long s = _abs(a[l] + a[r] - k);
			if (s < max) {
				max = s;
				cnt = 1;
				if (a[l] + a[r] > k) { r--; }
				else { l++; }
			}
			else if (s == max) {
				cnt++;
				if (a[l] + a[r] > k) { r--; }
				else { l++; }
			}
			else {
				if (a[l] + a[r] > k) { r--; }
				else { l++; }
			}
		}

		printf("%d\n", cnt);
		delete[] a;
	}
}