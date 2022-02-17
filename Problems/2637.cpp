#include <stdio.h>
#include <vector>
#include <utility>
using namespace std;
vector<int> dfs(vector<pair<int, int>> const* v, vector<vector<int>>& dp, int n, int now) {
	vector<int> res;
	res.resize(n + 1);
	if (!dp[now].empty()) return dp[now];
	if (now != n && v[now].empty()) {
		res[now] = 1;
		return dp[now] = res;
	}
	for (auto const& next : v[now]) {
		auto get = dfs(v, dp, n, next.first);
		for (int i = 0; i < get.size(); i++) {
			res[i] += next.second * get[i];
		}
	}
	return dp[now] = res;
}
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	auto v = new vector<pair<int, int>>[n + 1];
	for (int i = 0; i < m; i++) {
		int x, y, k;
		scanf("%d%d%d", &x, &y, &k);
		v[x].emplace_back(y, k);
	}
	vector<vector<int>> dp;
	dp.resize(n + 1);
	auto res = dfs(v, dp, n, n);
	for (int i = 1; i <= n; i++) {
		if (res[i]) {
			printf("%d %d\n", i, res[i]);
		}
	}
	delete[] v;
}