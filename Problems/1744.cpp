#include <stdio.h>
#include <algorithm>
int main() {
	int n;
	scanf("%d", &n);
	auto a = new int[n];
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	std::sort(a, a + n);
	int idx = n - 1;
	long long sum = 0;
	while (idx > 0 && a[idx] > 1 && a[idx - 1] > 1) {
		sum += a[idx] * a[idx - 1];
		idx -= 2;
	}
	if (a[idx] > 0) sum += a[idx--];
	int l = 0;
	while (l < idx && a[l] <= 0 && a[l + 1] <= 0) {
		sum += a[l] * a[l + 1];
		l += 2;
	}
	for (int i = l; i <= idx; i++) {
		sum += a[i];
	}
	printf("%lld", sum);
	delete[] a;
}