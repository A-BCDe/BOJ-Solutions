#include <stdio.h>
constexpr int M = 1000;
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	auto g1 = new int* [n + 1];
	auto g2 = new int* [n + 1];
	for (int i = 1; i <= n; i++) {
		g1[i] = new int[n + 1];
		g2[i] = new int[n + 1];
		for (int j = 1; j <= n; j++) {
			g1[i][j] = g2[i][j] = M;
			if (i == j) g1[i][j] = g2[i][j] = 0;
		}
	}
	for (int i = 0; i < m; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		g1[x][y] = g2[y][x] = 1;
	}
	for (int i = 1; i <= n; i++) {
		for (int s = 1; s <= n; s++) {
			for (int e = 1; e <= n; e++) {
				if (g1[s][e] > g1[s][i] + g1[i][e]) {
					g1[s][e] = g1[s][i] + g1[i][e];
				}
				if (g2[s][e] > g2[s][i] + g2[i][e]) {
					g2[s][e] = g2[s][i] + g2[i][e];
				}
			}
		}
	}
	int const mid = n / 2;
	int res = 0;
	for (int i = 1; i <= n; i++) {
		int sum1 = 0, sum2 = 0;
		for (int j = 1; j <= n; j++) {
			if (g1[i][j] && g1[i][j] < M) sum1++;
			if (g2[i][j] && g2[i][j] < M) sum2++;
		}
		if (sum1 > mid || sum2 > mid) res++;
	}
	printf("%d", res);
}