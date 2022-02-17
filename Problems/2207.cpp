#include <stdio.h>
#include <stack>
#include <vector>
using namespace std;
inline int index(int x) {
	if (x > 0) return x * 2;
	return index(-x) - 1;
}
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
int main() { // (x \/ y) = (~x -> y) = (~y -> x)
	int n, m;
	scanf("%d%d", &m, &n);
	auto v = new vector<int>[n * 2 + 1];
	auto u = new vector<int>[n * 2 + 1];
	for (int i = 0; i < m; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		v[index(-x)].push_back(index(y));
		v[index(-y)].push_back(index(x));
		u[index(x)].push_back(index(-y));
		u[index(y)].push_back(index(-x));
	}
	auto visited = new bool[n * 2 + 1]();
	stack<int> s;
	for (int i = 1; i <= n * 2; i++) {
		if (!visited[i]) dfs1(v, s, visited, i);
	}
	fill(visited, visited + n * 2 + 1, false);
	auto value = new int[n * 2 + 1]();
	int cnt = 1;
	while (!s.empty()) {
		auto const now = s.top(); s.pop();
		if (visited[now]) continue;
		vector<int> scv;
		dfs2(u, scv, visited, now);
		for (auto val : scv) {
			value[val] = cnt;
		} cnt++;
	}
	for (int i = 1; i <= n; i++) {
		if (value[i * 2 - 1] == value[i * 2]) {
			printf("OTL");
			return 0;
		}
	}
	printf("^_^");
}