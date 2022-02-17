#include <stdio.h>
void f(long long* a, long long k, long long min, long long max, long long idx) {
	if (min > max) return;
	auto const n = (max - min + 1);
	if (k >= n - 1) {
		a[idx + n - 1] = min;
		f(a, k - n + 1, min + 1, max, idx);
		return;
	}
	a[idx + k] = min;
	f(a, 0, min + 1, min + k, idx);
	f(a, 0, min + k + 1, max, idx + k + 1);
	return;
}
int main() {
	long long n, k;
	scanf("%lld%lld", &n, &k);
	auto a = new long long[n];
	f(a, k, 1, n, 0);
	for (int i = 0; i < n; i++) {
		printf("%lld ", a[i]);
	}
	delete[] a;
}