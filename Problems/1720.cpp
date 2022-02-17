#include <stdio.h>
using ll = long long;
int main() {
	int n;
	scanf("%d", &n);
	if (n == 1) {
		printf("1");
		return 0;
	}
	if (n == 2) {
		printf("3");
		return 0;
	}
	ll* a[3];
	for (auto& i : a) i = new ll[n + 3]();
	a[0][1] = 1;
	a[0][2] = 1;
	a[1][2] = 1;
	a[2][2] = 1;
	for (int i = 3; i <= n; i++) {
		a[0][i] += a[0][i - 1] + a[1][i - 1] + a[2][i - 1];
		a[1][i] += a[0][i - 2] + a[1][i - 2] + a[2][i - 2];
		a[2][i] += a[0][i - 2] + a[1][i - 2] + a[2][i - 2];
	}
	ll res = a[0][n] + a[1][n] + a[2][n];
	auto const x = n / 2;
	res += a[0][x] + a[1][x] + a[2][x];
	if (!(n & 1)) {
		res += ((a[0][x - 1] + a[1][x - 1] + a[2][x - 1]) << 1);
	}
	printf("%lld", res / 2);
}