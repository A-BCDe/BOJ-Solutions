#include <stdio.h>
#include <queue>
#include <utility>
using namespace std;
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	auto a = new char* [n];
	bool** visited[2];
	visited[0] = new bool* [n];
	visited[1] = new bool* [n];
	for (int i = 0; i < n; i++) {
		a[i] = new char[m + 1];
		visited[0][i] = new bool[m]();
		visited[1][i] = new bool[m]();
		scanf("%s", a[i]);
		for (int j = 0; j < m; j++) {
			a[i][j] -= '0';
		}
	}



	queue<pair<pair<int, int>, pair<int, int>>> q; // (벽 부순 횟수, 이동 거리), (x, y)
	q.push(make_pair(make_pair(0, 0), make_pair(0, 0)));
	while (!q.empty()) {
		auto const now = q.front(); q.pop();
		if (visited[now.first.first][now.second.first][now.second.second]) continue;
		visited[now.first.first][now.second.first][now.second.second] = true;
		if (now.second.first == n - 1 && now.second.second == m - 1) {
			printf("%d", now.first.second + 1);
			goto END;
		}
		if (now.second.first) {
			if (a[now.second.first - 1][now.second.second] && !now.first.first && !visited[1][now.second.first - 1][now.second.second]) {
				q.push(make_pair(make_pair(1, now.first.second + 1), make_pair(now.second.first - 1, now.second.second)));
			}
			else if (!a[now.second.first - 1][now.second.second] && !visited[now.first.first][now.second.first - 1][now.second.second]) {
				q.push(make_pair(make_pair(now.first.first, now.first.second + 1), make_pair(now.second.first - 1, now.second.second)));
			}
		}
		if (now.second.second) {
			if (a[now.second.first][now.second.second - 1] && !now.first.first && !visited[1][now.second.first][now.second.second - 1]) {
				q.push(make_pair(make_pair(1, now.first.second + 1), make_pair(now.second.first, now.second.second - 1)));
			}
			else if (!a[now.second.first][now.second.second - 1] && !visited[now.first.first][now.second.first][now.second.second - 1]) {
				q.push(make_pair(make_pair(now.first.first, now.first.second + 1), make_pair(now.second.first, now.second.second - 1)));
			}
		}
		if (now.second.first < n - 1) {
			if (a[now.second.first + 1][now.second.second] && !now.first.first && !visited[1][now.second.first + 1][now.second.second]) {
				q.push(make_pair(make_pair(1, now.first.second + 1), make_pair(now.second.first + 1, now.second.second)));
			}
			else if (!a[now.second.first + 1][now.second.second] && !visited[now.first.first][now.second.first + 1][now.second.second]) {
				q.push(make_pair(make_pair(now.first.first, now.first.second + 1), make_pair(now.second.first + 1, now.second.second)));
			}
		}
		if (now.second.second < m - 1) {
			if (a[now.second.first][now.second.second + 1] && !now.first.first && !visited[1][now.second.first][now.second.second + 1]) {
				q.push(make_pair(make_pair(1, now.first.second + 1), make_pair(now.second.first, now.second.second + 1)));
			}
			else if (!a[now.second.first][now.second.second + 1] && !visited[now.first.first][now.second.first][now.second.second + 1]) {
				q.push(make_pair(make_pair(now.first.first, now.first.second + 1), make_pair(now.second.first, now.second.second + 1)));
			}
		}
	}
	printf("-1");
	END:
	for (int i = 0; i < n; i++) {
		delete[] a[i];
		delete[] visited[0][i];
		delete[] visited[1][i];
	}
	delete[] visited[0];
	delete[] visited[1];
	delete[] a;
}