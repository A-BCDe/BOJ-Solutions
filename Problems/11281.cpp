#include <stdio.h>
#include <stack>
#include <vector>
using namespace std;
inline int index(int x) {
	if (x > 0) return x * 2;
	return index(-x) - 1;
}
inline int negate(int x) {
	if (x & 1) return x + 1;
	return x - 1;
}
void dfs1(vector<int> const* v, stack<int>& s, bool* visited, int now) {
	visited[now] = true;
	for (auto next : v[now]) {
		if (!visited[next]) dfs1(v, s, visited, next);
	}
	s.push(now);
}
void dfs2(vector<int> const* u, vector<int> &scc, bool* visited, int now) {
	visited[now] = true;
	scc.push_back(now);
	for (auto next : u[now]) {
		if (!visited[next]) dfs2(u, scc, visited, next);
	}
}
int main() { // (x \/ y) = (~x -> y) = (~y -> x)
	int n, m;
	scanf("%d%d", &n, &m);
	auto v = new vector<int>[n * 2 + 1];
	auto u = new vector<int>[n * 2 + 1];
	while (m--) {
		int x, y;
		scanf("%d%d", &x, &y);
		v[index(-x)].push_back(index(y));
		v[index(-y)].push_back(index(x));
		u[index(x)].push_back(index(-y));
		u[index(y)].push_back(index(-x));
	}
	auto visited = new bool[n * 2 + 1]();
	stack<int> s;
	for (int i = 1; i <= 2 * n; i++) {
		if (!visited[i]) {
			dfs1(v, s, visited, i);
		}
	}
	fill(visited, visited + n * 2 + 1, false);
	vector<vector<int>> scc;
	auto check = new int[n * 2 + 1]();
	int cnt = 1;
	while (!s.empty()) {
		auto const now = s.top(); s.pop();
		if (visited[now]) continue;
		vector<int> scv;
		dfs2(u, scv, visited, now);
		for (auto val : scv) {
			check[val] = cnt;
		}
		cnt++;
		scc.emplace_back(move(scv));
	}
	for (int i = 1; i <= n; i++) {
		if (check[i * 2 - 1] == check[i * 2]) {
			printf("0");
			return 0;
		}
	}
	printf("1\n");
	auto res = new int[n * 2 + 1]();
	for (auto const& scv : scc) {
		for (auto val : scv) {
			if (res[val]) {
				for (auto val1 : scv) {
					res[val1] = 1;
					res[negate(val1)] = 0;
				}
				break;
			}
			res[negate(val)] = 1;
		}
	}
	for (int i = 1; i <= n; i++) {
		printf("%d ", res[i * 2]);
	}
	delete[] visited;
	delete[] v;
	delete[] u;
}