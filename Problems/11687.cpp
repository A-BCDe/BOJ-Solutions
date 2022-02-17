#include <stdio.h>
int f(int n) {
	int res = 0;
	for (int i = 1; i <= n; i *= 5) {
		res += n / i;
	}
	return res;
}
int main() {
	int n;
	scanf("%d", &n);
	int l = 0, r = n * 5 + 1;
	while (l < r) {
		auto const m = (l + r) / 2;
		auto const x = f(m);
		if (x == n) {
			printf("%d", m * 5);
			return 0;
		}
		if (x < n) {
			l = m + 1;
			continue;
		}
		r = m;
	}
	printf("-1");
}