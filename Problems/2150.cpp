#include <stdio.h>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;
void dfs1(vector<int>* v, stack<int>& s, bool* visited, int i) {
	visited[i] = true;
	for (auto now : v[i]) {
		if (!visited[now]) dfs1(v, s, visited, now);
	}
	s.push(i);
}
void dfs2(vector<int>* v, vector<int>& scc, bool* visited, int i) {
	visited[i] = true;
	scc.push_back(i);
	for (auto now : v[i]) {
		if (!visited[now]) dfs2(v, scc, visited, now);
	}
}
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	auto v1 = new vector<int>[n + 1];
	auto v2 = new vector<int>[n + 1];
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		v1[a].push_back(b);
		v2[b].push_back(a);
	}
	stack<int> s;
	auto visited = new bool[n + 1]();
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) dfs1(v1, s, visited, i);
	}
	delete[] visited;
	visited = new bool[n + 1]();
	vector<vector<int>> res;
	while (!s.empty()) {
		auto const now = s.top(); s.pop();
		if (!visited[now]) {
			vector<int> scc;
			dfs2(v2, scc, visited, now);
			sort(scc.begin(), scc.end());
			res.emplace_back(move(scc));
		}
	}
	sort(res.begin(), res.end(), [](vector<int> const& a, vector<int> const& b) { return a[0] <= b[0]; });
	printf("%d\n", (int)res.size());
	for (auto const& v : res) {
		for (auto const now : v) {
			printf("%d ", now);
		}
		printf("-1\n");
	}
	delete[] visited;
	delete[] v2;
	delete[] v1;
}