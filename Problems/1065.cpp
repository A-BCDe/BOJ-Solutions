#include <stdio.h>
int f(int n) {
	int a[3] = { n / 100, (n / 10) % 10, n % 10 };
	return a[1] * 2 == a[2] + a[0];
}
int main() {
	int n;
	scanf("%d", &n);
	if (n < 100) {
		printf("%d", n);
		return 0;
	}
	int ans = 99;
	for (int i = 100; i <= n; i++) {
		ans += f(i);
	}
	printf("%d", ans);
}