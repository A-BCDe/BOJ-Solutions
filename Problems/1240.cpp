#include <algorithm>
#include <stdio.h>
#include <vector>
using namespace std;
void dfs(vector<pair<int, int>> const* v, int* visit, int* depth, int* first, int* dist, int now, int prev, int d, int l, int& idx) {
	visit[idx] = now;
	depth[idx] = d;
	first[now] = idx;
	dist[now] = l;
	for (auto const& next : v[now]) {
		if (next.first == prev) continue;
		idx++;
		dfs(v, visit, depth, first, dist, next.first, now, d + 1, l + next.second, idx);
		idx++;
		visit[idx] = now;
		depth[idx] = d;
	}
}
int init(int* t, int const* a, int tidx, int l, int r) {
	if (l == r) return t[tidx] = l;
	auto const m = (l + r) / 2;
	auto const x = init(t, a, tidx * 2, l, m);
	auto const y = init(t, a, tidx * 2 + 1, m + 1, r);
	return t[tidx] = (a[l] <= a[r] ? l : r);
}
int mini(int const* t, int const* a, int tidx, int start, int end, int l, int r) {
	if (end < l || r < start) return 0;
	if (start <= l && r <= end) return t[tidx];
	auto const m = (l + r) / 2;
	auto const x = mini(t, a, tidx * 2, start, end, l, m);
	auto const y = mini(t, a, tidx * 2 + 1, start, end, m + 1, r);
	if (!x) return y;
	if (!y) return x;
	return a[x] <= a[y] ? x : y;
}
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	auto v = new vector<pair<int, int>>[n + 1];
	for (int i = 1; i < n; i++) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		v[x].emplace_back(y, z);
		v[y].emplace_back(x, z);
	}
	int const N = n * 2 - 1;
	auto visit = new int[N + 1];
	auto depth = new int[N + 1];
	auto first = new int[n + 1];
	auto dist = new int[n + 1];
	auto t = new int[N * 4];
	int idx = 1;
	dfs(v, visit, depth, first, dist, 1, -1, 0, 0, idx);
	init(t, depth, 1, 1, N);
	while (m--) {
		int x, y;
		scanf("%d%d", &x, &y);
		if (first[x] > first[y]) swap(x, y);
		int c = mini(t, depth, 1, first[x], first[y], 1, N);
		printf("%d\n", dist[x] + dist[y] - 2 * dist[visit[c]]);
	}
	delete[] v;
}