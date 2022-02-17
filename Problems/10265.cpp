#include <algorithm>
#include <queue>
#include <stdio.h>
#include <stack>
#include <vector>
using namespace std;
vector<vector<int>> gv;
struct comp {
	bool operator()(int a, int b) {
		return gv[a].size() > gv[b].size();
	}
};
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
	int n, k;
	scanf("%d%d", &n, &k);
	auto v = new vector<int>[n + 1];
	auto u = new vector<int>[n + 1];
	for (int i = 1; i <= n; i++) { // 1 -> 2 -> 3 -> 2
		int x;
		scanf("%d", &x);
		v[i].push_back(x); // 1 -> 2
		u[x].push_back(i); // 1 <- 2
	}
	auto visited = new bool[n + 1]();
	stack<int> s;
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) dfs1(v, s, visited, i);
	}
	fill(visited, visited + n + 1, false);
	vector<vector<int>> scc;
	vector<int> deg;
	while (!s.empty()) {
		auto const now = s.top(); s.pop();
		if (visited[now]) continue;
		vector<int> scv;
		dfs2(u, scv, visited, now);
		sort(scv.begin(), scv.end());
		int cur = 0;
		auto visited2 = new bool[n + 1]();
		for (auto val : scv) {
			for (auto next : u[val]) {
				if (visited2[next]) continue;
				visited2[next] = true;
				for (int i = 0; i < scc.size(); i++) {
					auto const& vec = scc[i];
					auto p = lower_bound(vec.begin(), vec.end(), next);
					if (p == vec.end() || *p != next) continue;
					gv[i].push_back(scc.size());
					cur++;
				}
			}
		}
		deg.push_back(cur);
		delete[] visited2;
	} // gv : (1) -> (2 3)
	priority_queue<int, vector<int>, comp> pq;
	for (int i = 0; i < deg.size(); i++) {
		if (!deg[i]) {
			pq.push(i);
		}
	}
	
	while (!pq.empty()) {
		if (n <= k) {

		}
	}
	delete[] visited;
	delete[] v;
	delete[] u;
}