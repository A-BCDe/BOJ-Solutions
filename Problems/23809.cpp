#include <cstdio>
inline void print(int n, int cnt, bool fill, bool newline) {
	for (int i = 0; i < n; i++) {
		char c = fill ? '@' : ' ';
		for (int j = 0; j < n; j++) putchar('@');
		for (int j = 1; j < cnt - 1; j++) {
			for (int k = 0; k < n; k++) putchar(c);
		}
		for (int j = 0; j < n; j++) putchar('@');
		if (newline || i < n - 1) putchar('\n');
	}
}
int main() {
	int n;
	scanf("%d", &n);
	print(n, 5, false, true);
	print(n, 4, false, true);
	print(n, 3, true, true);
	print(n, 4, false, true);
	print(n, 5, false, false);
}