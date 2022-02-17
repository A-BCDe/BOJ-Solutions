#include <stdio.h>
#include <queue>
#include <vector>
#include <utility>
using namespace std;
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	auto a = new int[n + 1];
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	int r;
	scanf("%d", &r);
	auto v = new vector<pair<int, int>>[n + 1];
	for (int i = 0; i < r; i++) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		v[x].emplace_back(z, y);
	}
	auto visited = new bool[n + 1]();
	priority_queue<pair<long long, int>> pq;
	for (int i = 1; i <= n; i++) {
		pq.push(make_pair(-a[i], i));
	}
	int cnt = 0;
	while (!pq.empty()) {
		auto const now = pq.top(); pq.pop();
		if (visited[now.second]) continue;
		visited[now.second] = true;
		if (++cnt == m) {
			printf("%lld", -now.first);
			return 0;
		}
		for (auto const& next : v[now.second]) {
			if (!visited[next.second]) {
				pq.push(make_pair(-(a[next.second] -= next.first), next.second));
			}
		}
	}
	delete[] visited;
	delete[] v;
	delete[] a;
}