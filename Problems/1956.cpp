#include <stdio.h>
constexpr int M = 10000000;
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	auto a = new int* [n + 1];
	for (int i = 1; i <= n; i++) {
		a[i] = new int[n + 1];
		for (int j = 1; j <= n; j++) {
			a[i][j] = M;
			if (i == j) a[i][j] = 0;
		}
	}
	for (int i = 0; i < m; i++) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		a[x][y] = z;
	}
	for (int i = 1; i <= n; i++) {
		for (int s = 1; s <= n; s++) {
			for (int e = 1; e <= n; e++) {
				if (a[s][e] > a[s][i] + a[i][e]) {
					a[s][e] = a[s][i] + a[i][e];
				}
			}
		}
	}
	int min = M;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) continue;
			if (a[i][j] != M && a[j][i] != M && min > a[i][j] + a[j][i]) {
				min = a[i][j] + a[j][i];
			}
		}
	}
	if (min == M) printf("-1");
	else printf("%d", min);
}