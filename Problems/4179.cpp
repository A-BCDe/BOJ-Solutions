#include <iostream>
#include <queue>
#include <vector>
#include <utility>
using namespace std;
void fire(char* const* a, int r, int c, vector<pair<int, int>> &prev) {
	vector<pair<int, int>> v;
	for (auto const& now : prev) {
		if (now.first && a[now.first - 1][now.second] != 'F' && a[now.first - 1][now.second] != '#') {
			a[now.first - 1][now.second] = 'F';
			v.emplace_back(now.first - 1, now.second);
		}
		if (now.first < r - 1 && a[now.first + 1][now.second] != 'F' && a[now.first + 1][now.second] != '#') {
			a[now.first + 1][now.second] = 'F';
			v.emplace_back(now.first + 1, now.second);
		}
		if (now.second && a[now.first][now.second - 1] != 'F' && a[now.first][now.second - 1] != '#') {
			a[now.first][now.second - 1] = 'F';
			v.emplace_back(now.first, now.second - 1);
		}
		if (now.second < c - 1 && a[now.first][now.second + 1] != 'F' && a[now.first][now.second + 1] != '#') {
			a[now.first][now.second + 1] = 'F';
			v.emplace_back(now.first, now.second + 1);
		}
	}
	prev = std::move(v);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int r, c;
	cin >> r >> c;
	auto a = new char* [r];
	pair<int, int> init;
	bool b = true;
	vector<pair<int, int>> f;
	for (int i = 0; i < r; i++) {
		a[i] = new char[c + 1];
		cin >> a[i];
		for (int j = 0; j < c; j++) {
			if (a[i][j] == 'F') {
				f.emplace_back(i, j);
			}
			else if (b && a[i][j] == 'J') {
				init = make_pair(i, j);
				b = false;
			}
		}
	}
	fire(a, r, c, f);
	queue<pair<int, pair<int, int>>> q;
	q.push(make_pair(0, init));
	auto visited = new bool* [r];
	for (int i = 0; i < r; i++) {
		visited[i] = new bool[c]();
	}
	int cur = 0;
	while (!q.empty()) {
		auto const now = q.front(); q.pop();
		if (visited[now.second.first][now.second.second]) continue;
		visited[now.second.first][now.second.second] = true;
		if (now.second.first == 0 || now.second.second == 0 || now.second.first == r - 1 || now.second.second == c - 1) {
			printf("%d", now.first + 1);
			return 0;
		}
		if (cur != now.first) {
			cur = now.first;
			fire(a, r, c, f);
		}
		if (now.second.first && !visited[now.second.first - 1][now.second.second] && a[now.second.first - 1][now.second.second] != '#' && a[now.second.first - 1][now.second.second] != 'F') {
			q.push(make_pair(now.first + 1, make_pair(now.second.first - 1, now.second.second)));
		}
		if (now.second.first < r - 1 && !visited[now.second.first + 1][now.second.second] && a[now.second.first + 1][now.second.second] != '#' && a[now.second.first + 1][now.second.second] != 'F') {
			q.push(make_pair(now.first + 1, make_pair(now.second.first + 1, now.second.second)));
		}
		if (now.second.second && !visited[now.second.first][now.second.second - 1] && a[now.second.first][now.second.second - 1] != '#' && a[now.second.first][now.second.second - 1] != 'F') {
			q.push(make_pair(now.first + 1, make_pair(now.second.first, now.second.second - 1)));
		}
		if (now.second.second < c - 1 && !visited[now.second.first][now.second.second + 1] && a[now.second.first][now.second.second + 1] != '#' && a[now.second.first][now.second.second + 1] != 'F') {
			q.push(make_pair(now.first + 1, make_pair(now.second.first, now.second.second + 1)));
		}
	}
	printf("IMPOSSIBLE");
}