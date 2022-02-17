#include <stdio.h>
#include <queue>
#include <vector>
using ll = long long;
using namespace std;
struct comp {
	bool operator()(pair<ll, int> const& a, pair<ll, int> const& b) {
		return a.first > b.first;
	}
};
int main() {
	int V, E;
	scanf("%d%d", &V, &E);
	auto v = new vector<pair<ll, int>>[V + 1];
	for (int i = 0; i < E; i++) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		v[a].emplace_back(c, b);
		v[b].emplace_back(c, a);
	}
	auto visited = new bool[V + 1]();
	priority_queue<pair<ll, int>, vector<pair<ll, int>>, comp> pq;
	pq.push(make_pair(0, 1));
	ll res = 0;
	while (!pq.empty()) {
		auto const now = pq.top();
		pq.pop();
		if (visited[now.second]) continue;
		visited[now.second] = true;
		res += now.first;
		for (auto const& next : v[now.second]) {
			if (!visited[next.second]) {
				pq.push(next);
			}
		}
	}
	printf("%lld", res);
	delete[] visited;
	delete[] v;
}