#include <stdio.h>
#include <vector>
#include <utility>
using namespace std;
constexpr int M = 1000;
int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	auto a = new int* [n + 1];
	for (int i = 1; i <= n; i++) {
		a[i] = new int[n + 1]();
		for (int j = 1; j <= n; j++) {
			a[i][j] = M;
			if (i == j) a[i][j] = 0;
		}
	}
	for (int i = 0; i < k; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		a[x][y] = a[y][x] = 1;
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
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) continue;
			if (a[i][j] > 6) {
				printf("Big World!");
				return 0;
			}
		}
	}
	printf("Small World!");
}