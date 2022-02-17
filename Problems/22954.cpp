#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
int make_tree(vector<pair<int, int>>* v, vector<pair<int, int>>* tree, bool* visited, int idx) {
	visited[idx] = true;
	int size = 1;
	queue<pair<int, pair<int, int>>> q;
	for (auto const& now : v[idx]) if(!visited[now.second]) q.push({ now.first, { idx, now.second } });
	while (!q.empty()) {
		auto const now = q.front(); q.pop();
		if (visited[now.second.second]) continue;
		size++;
		visited[now.second.second] = true;
		tree[now.second.first].emplace_back(now.first, now.second.second);
		tree[now.second.second].emplace_back(now.first, now.second.first);
		for (auto const& next : v[now.second.second]) {
			if (visited[next.second]) continue;
			q.push({ next.first, { now.second.second, next.second } });
		}
	}
	return size;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, m;
	cin >> n >> m;
	auto v = new vector<pair<int, int>>[n + 1];
	for (int i = 1; i <= m; i++) {
		int x, y;
		cin >> x >> y;
		v[x].emplace_back(i, y);
		v[y].emplace_back(i, x);
	}
	vector<pair<int, vector<pair<int, int>>*>> trees;
	auto visited = new bool[n + 1]();
	for (int i = 1; i <= n; i++) {
		if (visited[i]) continue;
		auto tree = new vector<pair<int, int>>[n + 1];
		auto size = make_tree(v, tree, visited, i);
		trees.emplace_back(size, tree);
	}
	if (n < 3 || trees.size() > 2) {
		printf("-1");
		return 0;
	}
	if (trees.size() == 2) {
		if (trees[0].first == trees[1].first) {
			printf("-1");
			return 0;
		}

		return 0;
	}

}