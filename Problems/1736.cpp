#include <stdio.h>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
int f(int** a, int n, int m, int x, int y) {
	for (int i = x + y; i < n + m; i++) {
		for (int j = x; j < n && i - j >= y; j++) {
			if (i - j >= m) continue;
			if (a[j][i - j]) {
				// 1 0 1 0
				// 0 0 0 0
				// 0 1 0 0
				a[j][i - j] = 0;
				return f(a, n, m, j, i - j) + 1;
			}
		}
	}
	return 0;
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	auto a = new int* [n];
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		a[i] = new int[m];
		for (int j = 0; j < m; j++) {
			scanf("%d", &a[i][j]);
			if (a[i][j]) cnt++;
		}
	}

	int res = 0;
	while (cnt && res < n && res < m) {
		cnt -= f(a, n, m, 0, 0);
		res++;
	}

	printf("%d", res);

	for (int i = 0; i < n; i++) {
		delete[] a[i];
	}
	delete[] a;
}