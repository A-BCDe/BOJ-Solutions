#include <stdio.h>
int main() {
	int n;
	scanf("%d", &n);
	auto a = new long long[n];
	auto b = new long long[n];
	for (int i = 0; i < n; i++) {
		scanf("%lld%lld", &a[i], &b[i]);
	}
	long long res = a[0] * b[n - 1] - a[n - 1] * b[0];
	for (int i = 0; i < n - 1; i++) {
		res += a[i + 1] * b[i] - a[i] * b[i + 1];
	}
	if (res < 0)res = -res;
	if (res & 1) {
		printf("%lld.5", res / 2);
	}
	else printf("%lld.0", res / 2);
}