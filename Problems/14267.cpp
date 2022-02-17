#include <stdio.h>
#include <utility>
#include <vector>
using namespace std;
using ll = long long;
void dfs(pair<vector<int>, ll> const* v, ll* a, int now, int c) {
	c += v[now].second;
	a[now] = c;
	for (auto next : v[now].first) {
		dfs(v, a, next, c);
	}
}
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	auto v = new pair<vector<int>, ll>[n + 1];
	for (int i = 1; i <= n; i++) {
		int x;
		scanf("%d", &x);
		if (i - 1) v[x].first.push_back(i);
	}
	for (int i = 0; i < m; i++) {
		int x; ll y;
		scanf("%d%lld", &x, &y);
		v[x].second += y;
	}
	auto a = new ll[n + 1]();
	dfs(v, a, 1, 0);
	for (int i = 1; i <= n; i++) printf("%lld ", a[i]);
	delete[] a;
	delete[] v;
}