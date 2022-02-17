#include <stdio.h>
void f(int n, int x, int y, char **a, char c) {
	if (n == 1) {
		a[x][y] = c;
		return;
	}
	if (c == ' ') {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				a[x + i][y + j] = ' ';
			}
		}
		return;
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i == 1 && j == 1) {
				f(n / 3, x + i * n / 3, y + j * n / 3, a, ' ');
			}
			else f(n / 3, x + i * n / 3, y + j * n / 3, a, '*');
		}
	}
}
int main() {
	int n;
	scanf("%d", &n);
	auto a = new char*[n];
	for (int i = 0; i < n; i++) {
		a[i] = new char[n]();
	}
	f(n, 0, 0, a, '*');
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%c", a[i][j]);
		}
		printf("\n");
	}
	for (int i = 0; i < n; i++) {
		delete[] a[i];
	}
	delete[] a;
}