#include <stdio.h>
int main() {
	int n;
	scanf("%d", &n);
	unsigned long long a[21] = {};
	unsigned long long b[21] = {};
	int x;
	scanf("%d", &x);
	a[x] = 1;
	for (int i = 1; i < n - 1; i++) {
		scanf("%d", &x);
		for (int j = 0; j <= 20; j++) {
			if (j <= 20 - x) {
				b[j + x] = a[j];
			}
			if (j >= x) {
				b[j - x] += a[j];
			}
		}
		for (int j = 0; j < 21; j++) {
			a[j] = b[j];
		}
		for (int j = 0; j < 21; j++) b[j] = 0;
		printf("a[0] = %llu\n", a[0]);
	}
	scanf("%d", &n);
	printf("%llu", a[n]);
}