#include <stdio.h>
#include <vector>
using namespace std;
void dfs(vector<int> const* v, int* visit, int* depth, int* first, int d, int now, int& idx) {
	visit[idx] = now;
	depth[idx] = d;
	first[now] = idx;
	for (auto next : v[now]) {
		idx++;
		dfs(v, visit, depth, first, d + 1, next, idx);
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
	int tt;
	scanf("%d", &tt);
	while (tt--) {
		int n;
		scanf("%d", &n);
		int root = 1;
		auto r = new bool[n + 1];
		fill(r, r + n + 1, true);
		auto v = new vector<int>[n + 1];
		for (int i = 1; i < n; i++) {
			int x, y;
			scanf("%d%d", &x, &y);
			r[y] = false;
			v[x].push_back(y);
		}
		for (int i = 1; i <= n; i++) {
			if (r[i]) {
				root = i;
				break;
			}
		}
		delete[] r;
		auto visit = new int[n * 2]();
		auto depth = new int[n * 2]();
		auto first = new int[n + 1]();
		auto t = new int[n * 8]();
		int idx = 1;
		dfs(v, visit, depth, first, 1, root, idx);
		auto const N = n * 2 - 1;
		init(t, depth, 1, 1, N);
		int s, e;
		scanf("%d%d", &s, &e);
		if (first[s] > first[e]) swap(s, e);
		idx = mini(t, depth, 1, first[s], first[e], 1, N);
		printf("%d\n", visit[idx]);
		delete[] visit;
		delete[] depth;
		delete[] first;
		delete[] t;
		delete[] v;
	}
}