#include <stdio.h>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
int dfs(pair<int, int> const& cur, int** a, int** depth, vector<pair<int, int>>** v) {
	if (depth[cur.first][cur.second] != -1) return depth[cur.first][cur.second];
	int max = -1;
	for (auto const& now : v[cur.first][cur.second]) {
		auto res = dfs(now, a, depth, v);
		if (max < res) max = res;
	}
	return depth[cur.first][cur.second] = max + 1;
}
int main() {
	int n;
	scanf("%d", &n);
	auto a = new int* [n];
	auto v = new vector<pair<int, int>>* [n];
	auto depth = new int* [n];
	for (int i = 0; i < n; i++) {
		a[i] = new int[n];
		depth[i] = new int[n];
		v[i] = new vector<pair<int, int>>[n];
		for (int j = 0; j < n; j++) {
			depth[i][j] = -1;
			scanf("%d", &a[i][j]);
			if (i > 0) {
				if (a[i][j] > a[i - 1][j]) {
					v[i - 1][j].emplace_back(i, j);
				}
				else if (a[i][j] < a[i - 1][j]) {
					v[i][j].emplace_back(i - 1, j);
				}
			}
			if (j > 0) {
				if (a[i][j] > a[i][j - 1]) {
					v[i][j - 1].emplace_back(i, j);
				}
				else if (a[i][j] < a[i][j - 1]) {
					v[i][j].emplace_back(i, j - 1);
				}
			}
		}
	}
	int max = -1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (depth[i][j] == -1) {
				auto res = dfs(make_pair(i, j), a, depth, v);
				if (max < res) max = res;
			}
		}
	}
	printf("%d", max + 1);
	for (int i = 0; i < n; i++) {
		delete[] a[i];
		delete[] v[i];
		delete[] depth[i];
	}
	delete[] depth;
	delete[] v;
	delete[] a;
}