#include <stdio.h>
int main() {
	int n;
	scanf("%d", &n);
	auto a = new int** [n];
	for (int i = 0; i < n; i++) {
		a[i] = new int* [1024];
		for (int j = 0; j < 1024; j++) {
			a[i][j] = new int[10]();
		}
	}
	for (int i = 1; i < 10; i++) {
		int x = 1 << i;
		a[0][x][i] = 1;
	}
	for (int i = 1; i < n; i++) {
		for (int x = 0; x < 1024; x++) {
			for (int j = 0; j < 9; j++) {
				a[i][x | (1 << j)][j] = (a[i - 1][x][j + 1] + a[i][x | (1 << j)][j]) % 1000000000;
			}
			for (int j = 1; j < 10; j++) {
				a[i][x | (1 << j)][j] = (a[i - 1][x][j - 1] + a[i][x | (1 << j)][j]) % 1000000000;
			}
		}
	}
	int res = 0;
	for (int i = 0; i < 10; i++) {
		res = (a[n - 1][1023][i] + res) % 1000000000;
	}
	printf("%d", res);
}