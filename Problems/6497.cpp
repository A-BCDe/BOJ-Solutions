#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;
int main() {
	int n, m;
	while (true) {
		scanf("%d%d", &n, &m);
		if (!n && !m) return 0;
		auto v = new vector<pair<int, int>>[n];
		int sum = 0;
		while (m--) {
			int a, b, c;
			scanf("%d%d%d", &a, &b, &c);
			v[a].emplace_back(-c, b);
			v[b].emplace_back(-c, a);
			sum += c;
		}
		priority_queue<pair<int, int>> pq;
		for (auto const& now : v[0]) {
			pq.push(now);
		}
		auto visited = new bool[n]();
		visited[0] = true;
		int res = 0;
		while (!pq.empty()) {
			auto const now = pq.top(); pq.pop();
			if (visited[now.second]) continue;
			visited[now.second] = true;
			res -= now.first;
			for (auto const &next : v[now.second]) {
				if (!visited[next.second]) {
					pq.push(next);
				}
			}
		}
		printf("%d\n", sum - res);
		delete[] visited;
		delete[] v;
	}
}