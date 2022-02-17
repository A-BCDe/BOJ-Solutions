#include <stdio.h>
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		int* a[5];
		for (auto& now : a) now = new int[n + 3]();
		a[0][0] = a[0][1] = a[1][1] = a[2][1] = a[3][1] = 1;
		for (int i = 2; i <= n; i++) {
			a[0][i] = a[0][i - 2] + a[0][i - 1] + a[1][i - 1] + a[2][i - 1] + a[3][i - 1];
			a[1][i] = a[0][i - 1] + a[3][i - 1];
			a[2][i] = a[0][i - 1] + a[4][i - 1];
			a[3][i] = a[0][i - 1] + a[1][i - 1];
			a[4][i] = a[2][i - 1];
		}
		printf("%d\n", a[0][n]);
		for (auto& now : a) delete[] now;
	}
}