#include <algorithm>
#include <stdio.h>
#include <stack>
#include <vector>
using namespace std;
void dfs1(vector<int> const* v, stack<int>& s, bool* visited, int now) {
	visited[now] = true;
	for (auto next : v[now]) {
		if (!visited[next]) dfs1(v, s, visited, next);
	}
	s.push(now);
}
void dfs2(vector<int> const* u, vector<int>& scv, bool* visited, int now) {
	visited[now] = true;
	scv.push_back(now);
	for (auto next : u[now]) {
		if (!visited[next]) dfs2(u, scv, visited, next);
	}
}
int main() {
	int n, m;
	while (true) {
		scanf("%d", &n);
		if (!n) return 0;
		scanf("%d", &m);
		auto v = new vector<int>[n + 1];
		auto u = new vector<int>[n + 1];
		for (int i = 0; i < m; i++) {
			int x, y;
			scanf("%d%d", &x, &y);
			v[x].push_back(y);
			u[y].push_back(x);
		}
		auto visited = new bool[n + 1]();
		stack<int> s;
		for (int i = 1; i <= n; i++) {
			if (!visited[i]) dfs1(v, s, visited, i);
		}
		fill(visited, visited + n + 1, false);
		vector<vector<int>> scc;
		while (!s.empty()) {
			auto const now = s.top(); s.pop();
			if (visited[now]) continue;
			vector<int> scv;
			dfs2(u, scv, visited, now);
			sort(scv.begin(), scv.end());
			bool flag = false;
			for (auto val : scv) {
				for (auto next : v[val]) {
					auto p = lower_bound(scv.begin(), scv.end(), next);
					if (p == scv.end() || *p != next) {
						flag = true;
						goto END;
					}
				}
			}
		END:if(!flag) scc.emplace_back(move(scv));
		}
		vector<int> vec;
		for (auto const& scv : scc) {
			for (auto val : scv) {
				vec.push_back(val);
			}
		}
		sort(vec.begin(), vec.end());
		for (auto val : vec) {
			printf("%d ", val);
		} printf("\n");
		delete[] visited;
		delete[] v;
		delete[] u;
	}
}