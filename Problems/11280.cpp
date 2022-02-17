#include <algorithm>
#include <stdio.h>
#include <queue>
#include <stack>
#include <vector>
using namespace std;
inline int index(int x) {
	if (x > 0) return x * 2;
	return index(-x) - 1;
}
void dfs1(vector<vector<int>> const& v, stack<int>& s, bool* visited, int now) {
	visited[now] = true;
	for (auto next : v[now]) {
		if (!visited[next]) {
			dfs1(v, s, visited, next);
		}
	}
	s.push(now);
}
void dfs2(vector<vector<int>> const& u, vector<int>& scc, bool* visited, int now) {
	visited[now] = true;
	scc.push_back(now);
	for (auto next : u[now]) {
		if (!visited[next]) {
			dfs2(u, scc, visited, next);
		}
	}
}
int main() { // x \/ y = (~x -> y) = (~y -> x)
	int n, m;
	scanf("%d%d", &n, &m);
	auto v = vector<vector<int>>(n * 2 + 1); // x, -1, 1, -2, 2, ..., -n, n
	auto u = vector<vector<int>>(n * 2 + 1);
	while (m--) {
		int x, y;
		scanf("%d%d", &x, &y);
		v[index(-x)].push_back(index(y));
		v[index(-y)].push_back(index(x));
		u[index(x)].push_back(index(-y));
		u[index(y)].push_back(index(-x));
	}
	auto visited = new bool[2 * n + 1]();
	stack<int> s;
	for (int i = 1; i <= 2 * n; i++) {
		if (!visited[i]) {
			dfs1(v, s, visited, i);
		}
	}
	fill(visited, visited + n * 2 + 1, false);
	auto res = new int[n * 2 + 1]();
	int cnt = 1;
	while (!s.empty()) {
		auto const now = s.top(); s.pop();
		if (visited[now]) continue;
		vector<int> scc;
		dfs2(u, scc, visited, now);
		for (auto val : scc) {
			res[val] = cnt;
		}
		cnt++;
	}
	for (int i = 1; i <= n; i++) {
		if (res[i * 2 - 1] == res[i * 2]) {
			printf("0");
			return 0;
		}
	}
	printf("1");
	delete[] visited;
}