#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, m, k, x;
	cin >> n >> m >> k >> x;
	auto v = new vector<int>[n + 1];
	while (m--) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
	}
	queue<pair<int, int>> q;
	auto visited = new bool[n + 1]();
	q.push({ x, 0 });
	vector<int> res;
	while (!q.empty()) {
		auto const now = q.front();
		q.pop();
		if (visited[now.first]) continue;
		visited[now.first] = true;
		if (now.second == k) {
			res.push_back(now.first);
			continue;
		}
		for (auto next : v[now.first]) {
			if (!visited[next]) q.push({ next, now.second + 1 });
		}
	}
	sort(res.begin(), res.end());
	if (res.empty()) cout << -1;
	else for (auto now : res) cout << now << '\n';
}