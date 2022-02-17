#include <stdio.h>
#include <algorithm>
void f(char const* a, char *b, int c, int l, int v, int n, int cur, int cnt) {
	if (cnt == l) {
		if (v == 0 || n < 2) return;
		for (int i = 0; i < l; i++) {
			printf("%c", b[i]);
		}
		printf("\n");
		return;
	}
	for (int i = cur; i < c; i++) {
		b[cnt] = a[i];
		if (a[i] == 'a' || a[i] == 'e' || a[i] == 'i' || a[i] == 'o' || a[i] == 'u') {
			f(a, b, c, l, v + 1, n, i + 1, cnt + 1);
		}
		else {
			f(a, b, c, l, v, n + 1, i + 1, cnt + 1);
		}
	}
}
int main() {
	int l, c;
	scanf("%d%d", &l, &c);
	auto a = new char[c];
	for (int i = 0; i < c; i++) {
		char x[2];
		scanf("%s", x);
		a[i] = x[0];
	}
	std::sort(a, a + c);
	auto b = new char[l];
	f(a, b, c, l, 0, 0, 0, 0);

	delete[] b;
	delete[] a;
}