#include <stdio.h>
#include <vector>
#include <utility>
using namespace std;
void dfs(vector<pair<int, int>> const* v, int* visit, int* depth, int* first, pair<int, int>* minmax, int now, int prev, int d, pair<int, int> mm, int& idx) {
	visit[idx] = now;
	depth[idx] = d;
	first[now] = idx;
	minmax[now] = mm;
	for (auto const& next : v[now]) {
		if (next.first == prev) continue;

	}
}
int main() {
	int n;
	scanf("%d", &n);
	auto v = new vector<pair<int, int>>[n + 1];
	for (int i = 1; i < n; i++) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		v[x].emplace_back(y, z);
		v[y].emplace_back(x, z);
	}
	auto const N = n * 2 - 1;
	auto visit = new int[n * 2];
	auto depth = new int[n * 2];
	auto first = new int[n + 1];
	auto minmax = new pair<int, int>[n + 1];
	auto t = new pair<int, pair<int, int>>[N * 4](); // depth, min dist, max dist
	int idx = 1;
	dfs(v, visit, depth, first, minmax, 1, -1, 1, { 1000001, 0 }, idx);
}