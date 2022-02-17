#include <stdio.h>
inline void A(char c) {
	if(c == '*') printf("*");
	else printf(" ");
}
void f(char **a, int n, int x, int y) {
	if(n == 1) {
		a[x][y] = '*';
		return;
	}
	for(int i = 0; i < (1 << (n + 1)) - 3; i++) {
		a[x][y + i] = '*';
	}
	if(n & 1) {
		for(int i = 1; i < (1 << n) - 1; i++) {
			a[x - i][y + i] = a[x - i][y + (1 << (n + 1)) - 4 - i] = '*';
		}
		f(a, n - 1, x - (1 << (n - 1)) + 1, y + (1 << (n - 1)));
	}
	else {
		for(int i = 1; i < (1 << n) - 1; i++) {
			a[x + i][y + i] = a[x + i][y + (1 << (n + 1)) - 4 - i] = '*';
		}
		f(a, n - 1, x + (1 << (n - 1)) - 1, y + (1 << (n - 1)));
	}
}
inline int cut(int n, int i) {
	if(n & 1) {
		return ((1 << n) - 2) - i;
	}
	else return i;
}
int main() {
	int n; scanf("%d", &n);
	auto a = new char*[(1 << n) - 1];
	for(int i = 0; i < (1 << n) - 1; i++) {
		a[i] = new char[(1 << (n + 1)) - 3]();
	}
	f(a, n, (n & 1 ? ((1 << n) - 2) : 0), 0);
	for(int i = 0; i < (1 << n) - 1; i++) {
		for(int j = 0; j < (1 << (n + 1)) - 3 - cut(n, i); j++) {
			A(a[i][j]);
		} if(i != (1 << n) - 2) printf("\n");
	}
}