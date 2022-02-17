#include <stdio.h>
int main() {
	int n;
	scanf("%d", &n);
	auto a = new int* [10];
	for (int i = 0; i < 10; i++) {
		a[i] = new int[n + 1]();
		a[i][1] = 1;
	}
	a[0][1] = 0;
	for (int i = 2; i <= n; i++) {
		a[0][i] = a[1][i - 1];
		a[9][i] = a[8][i - 1];
		for (int j = 1; j < 9; j++) {
			a[j][i] = (a[j - 1][i - 1] + a[j + 1][i - 1]) % 1000000000;
		}
	}
	int x = 0;
	for (int i = 0; i < 10; i++) {
		x = (x + a[i][n]) % 1000000000;
	}
	printf("%d", x);
	for (int i = 0; i < 10; i++) {
		delete[] a[i];
	}
	delete[] a;
}