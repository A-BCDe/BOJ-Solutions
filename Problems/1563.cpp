#include <stdio.h>
int main() {
	int n;
	scanf("%d", &n);
	int* a[6];
	for (int i = 0; i < 6; i++) {
		a[i] = new int[n + 1]();
	}
	a[0][1] = 1; // O
	a[1][1] = 1; // A
	a[2][1] = 0;
	a[3][1] = 1; // L
	a[4][1] = 0;
	a[5][1] = 0;
	for (int i = 2; i <= n; i++) {
		a[0][i] = (a[0][i - 1] + a[1][i - 1] + a[2][i - 1]) % 1000000;
		a[1][i] = a[0][i - 1];
		a[2][i] = a[1][i - 1];
		a[3][i] = (a[0][i - 1] + a[1][i - 1] + a[2][i - 1] + a[3][i - 1] + a[4][i - 1] + a[5][i - 1]) % 1000000;
		a[4][i] = a[3][i - 1];
		a[5][i] = a[4][i - 1];
	}
	int res = 0;
	for (int i = 0; i < 6; i++) {
		res += a[i][n];
	}
	printf("%d", res % 1000000);
	for (int i = 0; i < 6; i++) {
		delete[] a[i];
	}
}