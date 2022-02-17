#include <stdio.h>
int max(int a, int b) { return a > b ? a : b; }
int main() {
	int n;
	scanf("%d", &n);
	auto a = new int[n];
	auto arr = new int* [n];
	for (int i = 0; i < n; i++) {
		arr[i] = new int[n]();
		scanf("%d", &a[i]);
	}

	for (int i = n - 2; i >= 0; i--) {
		arr[0][i] = arr[0][i + 1] + a[i + 1] * (n - 1 - i);
		arr[n - 1 - i][n - 1] = arr[n - 2 - i][n - 1] + a[n - 2 - i] * (n - 1 - i);
		for (int j = 1; j + i < n - 1; j++) {
			arr[j][j + i] = max(arr[j - 1][j + i] + a[j - 1] * (n - 1 - i), arr[j][j + i + 1] + a[j + i + 1] * (n - 1 - i));
		}
	}

	int m = 0;
	for (int i = 0; i < n; i++) {
		m = max(m, arr[i][i] + a[i] * n);
	}
	printf("%d", m);

	for (int i = 0; i < n; i++) {
		delete[] arr[i];
	}
	delete[] arr;
	delete[] a;
}