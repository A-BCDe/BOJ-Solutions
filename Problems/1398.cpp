#include <stdio.h>
int main() {
	int tt;
	scanf("%d", &tt);
	while (tt--) {
		long long n;
		scanf("%lld", &n);
		int a[16] = {};
		int m;
		for (m = 0; n > 0; m++) {
			a[m] = n % 10;
			n /= 10;
		}
		int sum = 0;
		for (int i = 0; i < m; i += 2) {
			int x = a[i] + 10 * a[i + 1];
			int min = a[i] + a[i + 1];
			for (int twofive = 1; x >= twofive * 25; twofive++) {
				int const y = x - 25 * twofive;
				int const ten = y / 10;
				int const one = y % 10;
				if (twofive + ten + one < min) min = twofive + ten + one;
			}
			sum += min;
		}
		printf("%d\n", sum);
	}
}