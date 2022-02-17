#include <stdio.h>
int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	int a[201] = {};
	a[0] = 1;
	for (int i = 0; i < k; i++) {
		for (int j = n; j >= 0; j--) {
			for (int l = n - j; l > 0; l--) {
				a[j + l] += a[j];
				a[j + l] %= 1000000000;
			}
		}
	}
	printf("%d", a[n]);
}