#include <algorithm>
#include <stdio.h>
int main() {
	int n, m;
	while (true) {
		scanf("%d%d", &n, &m);
		if (!n && !m) return 0;
		auto a = new int* [n];
		int res = 0;
		for (int i = 0; i < n; i++) {
			a[i] = new int[m];
			for (int j = 0; j < m; j++) {
				scanf("%d", &a[i][j]);
				if (!a[i][j] || !i || !j) { if (!res) res = a[i][j]; continue; }
				if (res < (a[i][j] = std::min({ a[i][j - 1], a[i - 1][j - 1], a[i - 1][j] }) + 1)) res = a[i][j];
			}
		}
		printf("%d\n", res);
		for (int i = 0; i < n; i++) {
			delete[] a[i];
		} delete[] a;
	}
}