#include <stdio.h>
constexpr int M = 1000;
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
		int s, e;
		scanf("%d%d", &s, &e);
		a[s][e] = a[e][s] = 1;
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
	int maxi = 0;
	for (int i = 1; i <= n; i++) {
		int sum = 0;
		for (int j = 1; j <= n; j++) {
			sum += a[i][j];
		}
		if (min > sum) {
			min = sum;
			maxi = i;
		}
	}
	printf("%d", maxi);
}