#include <stdio.h>
#include <vector>
using namespace std;
void dfs(vector<int> const* v, int* visit, int* depth, int* first, int root, int prev, int d, int& idx) {
	visit[idx] = root;
	depth[idx] = d;
	first[root] = idx;
	for (auto next : v[root]) {
		if (prev == next) continue;
		idx++;
		dfs(v, visit, depth, first, next, root, d + 1, idx);
		idx++;
		visit[idx] = root;
		depth[idx] = d;
	}
}
int init(int* t, int const* a, int tidx, int l, int r) {
	if (l == r) return t[tidx] = l;
	auto const m = (l + r) / 2;
	auto const x = init(t, a, tidx * 2, l, m);
	auto const y = init(t, a, tidx * 2 + 1, m + 1, r);
	return t[tidx] = (a[x] < a[y] ? x : y);
}
int mini(int const* t, int const* a, int tidx, int start, int end, int l, int r) {
	if (end < l || r < start) return 0;
	if (start <= l && r <= end) return t[tidx];
	auto const m = (l + r) / 2;
	auto const x = mini(t, a, tidx * 2, start, end, l, m);
	auto const y = mini(t, a, tidx * 2 + 1, start, end, m + 1, r);
	if (!x) return y;
	if (!y) return x;
	return a[x] < a[y] ? x : y;
}
int main() {
	int n;
	scanf("%d", &n);
	auto v = new vector<int>[n + 1];
	for (int i = 1; i < n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	auto const N = n * 2 - 1;
	auto visit = new int[n * 2];
	auto depth = new int[n * 2];
	auto first = new int[n + 1];
	auto t = new int[N * 4]();
	int idx = 1;
	dfs(v, visit, depth, first, 1, -1, 1, idx);
	init(t, depth, 1, 1, N);
	int m;
	scanf("%d", &m);
	while (m--) {
		int x, y;
		scanf("%d%d", &x, &y);
		if (first[x] > first[y]) swap(x, y);
		idx = mini(t, depth, 1, first[x], first[y], 1, N);
		printf("%d\n", visit[idx]);
	}
}