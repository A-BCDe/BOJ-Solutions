#include <algorithm>
#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;
void dfs(vector<int> const* v, bool* visited, int now) {
	visited[now] = true;
	printf("%d ", now);
	for (auto next : v[now]) {
		if (!visited[next]) dfs(v, visited, next);
	}
}
int main() {
	int n, m, root;
	scanf("%d%d%d", &n, &m, &root);
	auto v = new vector<int>[n + 1];
	while (m--) {
		int x, y;
		scanf("%d%d", &x, &y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for (int i = 1; i <= n; i++) {
		sort(v[i].begin(), v[i].end());
	}
	auto visited = new bool[n + 1]();
	dfs(v, visited, root);
	printf("\n");
	fill(visited, visited + n + 1, false);
	queue<int> q;
	q.push(root);
	while (!q.empty()) {
		auto const now = q.front(); q.pop();
		if (visited[now]) continue;
		visited[now] = true;
		printf("%d ", now);
		for (auto next : v[now]) {
			if (!visited[next]) q.push(next);
		}
	}
}