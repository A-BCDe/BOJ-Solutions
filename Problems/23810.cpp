#include <cstdio>
void print(int n, int cnt, bool newline) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < cnt * n; j++) putchar('@');
		if (newline || i < n - 1) putchar('\n');
	}
}
int main() {
	int n;
	scanf("%d", &n);
	print(n, 5, true);
	print(n, 1, true);
	print(n, 5, true);
	print(n, 1, true);
	print(n, 1, false);
}