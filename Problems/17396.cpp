#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	auto b = new bool[n]();
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		b[i] = (x == 1 && i != n - 1);
	}
	auto v = new vector<pair<long long, int>>[n];
	for (int i = 0; i < m; i++) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		if (b[x] || b[y]) continue;
		v[x].emplace_back(-z, y);
		v[y].emplace_back(-z, x);
	}
	priority_queue<pair<long long, int>> pq;
	pq.push({ 0, 0 });
	auto visited = new bool[n]();
	while (!pq.empty()) {
		auto const now = pq.top(); pq.pop();
		if (visited[now.second]) continue;
		visited[now.second] = true;
		if (now.second == n - 1) {
			printf("%lld", -now.first);
			return 0;
		}
		for (auto const& next : v[now.second]) {
			if (!visited[next.second]) {
				pq.push({ now.first + next.first, next.second });
			}
		}
	}
	printf("-1");
}