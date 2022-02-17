#include <stdio.h>
int main() {
	int n;
	scanf("%d", &n);
	auto a = new int[n + 1]();
	for (int i = 2; i <= n; i++) {
		a[i] = a[i - 1] + 1;
		if (i % 3 == 0) {
			int const x = a[i / 3] + 1;
			a[i] = a[i] > x ? x : a[i];
		}
		if (i % 2 == 0) {
			int const x = a[i / 2] + 1;
			a[i] = a[i] > x ? x : a[i];
		}
	}
	printf("%d", a[n]);
	delete[] a;
}