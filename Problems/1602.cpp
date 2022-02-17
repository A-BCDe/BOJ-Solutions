#include <stdio.h>
#include <queue>
#include <vector>
#include <utility>
using namespace std;
int main() {
	int n, m, q;
	scanf("%d%d%d", &n, &m, &q);
	auto a = new int[n + 1];
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	auto v = new vector<pair<int, int>>[n + 1];
	for (int i = 0; i < m; i++) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		v[x].emplace_back(-z, y);
		v[y].emplace_back(-z, x);
	}
	while (q--) {
		int s, e;
		scanf("%d%d", &s, &e);
		auto visited = new bool[n + 1]();
		priority_queue<pair<int, pair<int, int>>> pq; // -dist, dog max, #
		pq.push(make_pair(-a[s], make_pair(a[s], s)));
		while (!pq.empty()) {
			auto const now = pq.top(); pq.pop();
			if (visited[now.second.second]) continue;
			visited[now.second.second] = true;
			if (now.second.second == e) {
				printf("%d\n", -now.first);
				goto END;
			}
			for (auto const& next : v[now.second.second]) {
				if (!visited[next.second]) {
					if (now.second.first >= a[next.second]) {
						pq.push(make_pair(now.first + next.first, make_pair(now.second.first, next.second)));
					}
					else {
						pq.push(make_pair(now.first + next.first + now.second.first - a[next.second], make_pair(a[next.second], next.second)));
					}
				}
			}
		}
		printf("-1\n");
	END:delete[] visited;
	}
	delete[] v;
	delete[] a;
}