#include <stdio.h>
#include <queue>
#include <vector>
#include <utility>
using namespace std;
struct comp {
	bool operator()(pair<int, pair<int, int>> const& a, pair<int, pair<int, int>> const& b) {
		return a.second.first * a.second.second > b.second.first * b.second.second;
} };
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	auto v = new vector<pair<int, pair<int, int>>>[n];
	for (int i = 0; i < m; i++) {
		int a, b, c, d;
		scanf("%d%d%d%d", &a, &b, &c, &d);
		v[a].emplace_back(b, make_pair(c, d));
		v[b].emplace_back(a, make_pair(c, d));
	}
	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, comp> pq;
	pq.push(make_pair(0, make_pair(0, 0)));
	auto visited = new int[n];
	for (int i = 0; i < n; i++) visited[i] = -1;
	while (!pq.empty()) {
		auto const now = pq.top(); pq.pop();
		if (visited[now.first] >= 0) {
			if (visited[now.first] > now.second.first * now.second.second) {
				visited[now.first] = now.second.first * now.second.second;
			}
			else continue;
		}
		if (now.first == n - 1) {
			printf("%d", now.second.first * now.second.second);
			return 0;
		}
		visited[now.first] = now.second.first * now.second.second;
		for (auto const& next : v[now.first]) {
			if (visited[next.first] == -1) {
				if (now.second.first + now.second.second + next.second.first + next.second.second <= 1000) {
					pq.push(make_pair(next.first, make_pair(next.second.first + now.second.first, next.second.second + now.second.second)));
				}
			}
		}
	}
	delete[] visited;
	printf("-1");
	delete[] v;
}