#include <queue>
#include <stdio.h>
#include <vector>
using namespace std;
using ll = long long;
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	auto v = new vector<pair<ll, int>>[n + 1]();
	while (m--) {
		int x, y;
		ll z;
		scanf("%d%d%lld", &x, &y, &z);
		v[x].emplace_back(-z, y);
	}
	int s, e;
	scanf("%d%d", &s, &e);
	priority_queue<pair<ll, int>> pq;
	pq.push({ 0, s });
	auto visited = new bool[n + 1]();
	while (!pq.empty()) {
		auto const now = pq.top(); pq.pop();
		if (visited[now.second]) continue;
		visited[now.second] = true;
		if (now.second == e) {
			printf("%lld", -now.first);
			return 0;
		}
		for (auto const& next : v[now.second]) {
			if (visited[next.second]) continue;
			pq.push({ next.first + now.first, next.second });
		}
	}
	delete[] visited;
	delete[] v;
}