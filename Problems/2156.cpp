#include <stdio.h>
int max(int a, int b) { return a > b ? a : b; }
int main() {
	int n;
	scanf("%d", &n);
	auto a = new int*[2];
	a[0] = new int[n]();
	a[1] = new int[n]();
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		if (i == 0) a[0][0] = x;
		else if (i == 1) { a[0][1] = x; a[1][1] = a[0][0] + x; }
		else {
			a[0][i] = max(max(a[0][i - 2], a[1][i - 2]), max(a[0][i - 3], a[1][i - 3])) + x;
			a[1][i] = a[0][i - 1] + x;
		}
		//printf("%4d : %4d %4d\n", x, a[0][i], a[1][i]);
	}
	int const x = n > 1 ? max(a[0][n - 2], a[1][n - 2]) : 0;
	printf("%d", max(x, max(a[0][n - 1], a[1][n - 1])));
	delete[] a[0];
	delete[] a[1];
	delete[] a;
}