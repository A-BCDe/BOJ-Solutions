#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
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
	int k;
	scanf("%d", &k);
	auto c = new int* [k];
	for (int i = 0; i < k; i++) {
		c[i] = new int[n + 1]();
		int x;
		scanf("%d", &x);
		for (int j = 1; j <= n; j++) {
			c[i][j] = a[x][j] + a[j][x];
		}
	}
	int min = M;
	vector<int> v;
	for (int j = 1; j <= n; j++) {
		int max = 0;
		int i = 0;
		for (; i < k; i++) {
			if (c[i][j] >= M) break;
			if (max < c[i][j]) max = c[i][j];
		}
		if (i != k) continue;
		if (min == max) {
			v.push_back(j);
		}
		if (min > max) {
			min = max;
			v.clear();
			v.push_back(j);
		}
	}
	sort(v.begin(), v.end());
	for (auto now : v) {
		printf("%d ", now);
	}
}