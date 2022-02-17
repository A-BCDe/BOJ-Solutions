#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
int main() {
	int n, m, x;
	scanf("%d%d%d", &n, &m, &x);
	auto v = new vector<pair<int, int>>[n + 1]; // T, E
	auto u = new vector<pair<int, int>>[n + 1];
	for (int i = 0; i < m; i++) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		v[a].emplace_back(-c, b);
		u[b].emplace_back(-c, a);
	}
	priority_queue<pair<int, int>> pqv, pqu;
	pqv.push(make_pair(0, x));
	pqu.push(make_pair(0, x));
	auto dist = new int[n + 1]();
	auto visited = new bool[n + 1]();
	while (!pqv.empty()) {
		auto const now = pqv.top(); pqv.pop();
		if (visited[now.second]) continue;
		visited[now.second] = true;
		dist[now.second] -= now.first;
		for (auto const& next : v[now.second]) {
			if (!visited[next.second]) pqv.push(make_pair(next.first + now.first, next.second));
		}
	}
	delete[] visited;
	visited = new bool[n + 1]();
	while (!pqu.empty()) {
		auto const now = pqu.top(); pqu.pop();
		if (visited[now.second]) continue;
		visited[now.second] = true;
		dist[now.second] -= now.first;
		for (auto const& next : u[now.second]) {
			if (!visited[next.second]) pqu.push(make_pair(next.first + now.first, next.second));
		}
	}
	int max = 0;
	for (int i = 1; i <= n; i++) {
		if (max < dist[i]) max = dist[i];
	}
	printf("%d", max);
}