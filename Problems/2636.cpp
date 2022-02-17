#include <stdio.h>
#include <map>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
bool empty(int** a, int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] == 1) return false;
		}
	}
	return true;
}
int main() {
	int m, n;
	scanf("%d%d", &m, &n);
	auto a = new int* [m];
	for (int i = 0; i < m; i++) {
		a[i] = new int[n];
		for (int j = 0; j < n; j++) {
			scanf("%d", &a[i][j]);
		}
	}

	int time = 0;
	vector<pair<int, int>> v;
	while (!empty(a, m, n)) {
		time++;
		v.clear();
		auto visited = new bool* [m];
		for (int i = 0; i < m; i++) {
			visited[i] = new bool[n]();
		}

		queue<pair<int, int>> q;
		q.push(make_pair(0, 0));
		while (!q.empty()) {
			auto const now = q.front(); q.pop();
			if (visited[now.first][now.second]) continue;
			visited[now.first][now.second] = true;
			if (a[now.first][now.second] == 1) {
				v.emplace_back(now);
				continue;
			}
			if (now.first > 0 && !visited[now.first - 1][now.second]) {
				q.push(make_pair(now.first - 1, now.second));
			}
			if (now.second > 0 && !visited[now.first][now.second - 1]) {
				q.push(make_pair(now.first, now.second - 1));
			}
			if (now.first < m - 1 && !visited[now.first + 1][now.second]) {
				q.push(make_pair(now.first + 1, now.second));
			}
			if (now.second < n - 1 && !visited[now.first][now.second + 1]) {
				q.push(make_pair(now.first, now.second + 1));
			}
		}
		
		for (auto& now : v) {
			a[now.first][now.second] = 0;
		}

		for (int i = 0; i < m; i++) {
			delete[] visited[i];
		}
		delete[] visited;
	}
	printf("%d\n%d", time, v.size());

	for (int i = 0; i < m; i++) {
		delete[] a[i];
	}
	delete[] a;
}