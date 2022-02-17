#include <iostream>
#include <queue>
#include <vector>
using namespace std;
using ll = long long;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin >> n;
	auto v = new vector<pair<ll, int>>[n];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ll x; cin >> x;
			if (i < j) {
				v[i].emplace_back(-x, j);
				v[j].emplace_back(-x, i);
			}
		}
	}
	auto visited = new bool[n]();
	priority_queue<pair<ll, int>> pq;
	pq.push({ 0, 0 });
	ll res = 0;
	while (!pq.empty()) {
		auto const now = pq.top(); pq.pop();
		if (visited[now.second]) continue;
		visited[now.second] = true;
		res -= now.first;
		for (auto const& next : v[now.second]) {
			if (visited[next.second]) continue;
			pq.push(next);
		}
	}
	cout << res;
	delete[] visited;
	delete[] v;
}