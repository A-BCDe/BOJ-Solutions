#include <stdio.h>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	auto v = new vector<pair<int, int>>[n + 1];
	while (m--) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		if (a == b) continue;
		v[a].emplace_back(-c, b);
		v[b].emplace_back(-c, a);
	}
	priority_queue<pair<int, int>> pq;
	auto visited = new bool[n + 1]();
	visited[1] = true;
	for (auto const &next : v[1]) {
		pq.push({ next.first, next.second });
	}
	int res = 0;
	while (!pq.empty()) {
		auto const now = pq.top(); pq.pop();
		if (visited[now.second]) continue;
		visited[now.second] = true;
		res -= now.first;
		for (auto const &next : v[now.second]) {
			if (visited[next.second]) continue;
			pq.push(next);
		}
	}
	printf("%d", res);
}