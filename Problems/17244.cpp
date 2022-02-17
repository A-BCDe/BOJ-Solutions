#include <stdio.h>
#include <map>
#include <queue>
#include <vector>
using namespace std;
struct pos {
	int x, y;
	bool operator()(pos const& a, pos const& b) const {
		return a.x < b.x || (a.x == b.x && a.y < b.y);
	}
};
struct elem { pos p; int obj, cnt; };
int main() {
	int n, m;
	scanf("%d%d", &m, &n);
	auto a = new char*[n];
	int obj = 0;
	pos s, e;
	map<pos, int, pos> mp;
	auto visited = new bool** [n];
	for (int i = 0; i < n; i++) {
		a[i] = new char[m + 1];
		visited[i] = new bool* [m];
		scanf("%s", a[i]);
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 'X') {
				mp[{i, j}] = (1 << obj);
				obj++;
			}
			if (a[i][j] == 'S') s.x = i, s.y = j;
			if (a[i][j] == 'E') e.x = i, e.y = j;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			visited[i][j] = new bool[1 << obj]();
			if (a[i][j] == '#') {
				for (int k = 0; k < (1 << obj); k++) {
					visited[i][j][k] = true;
				}
			}
		}
	}
	queue<elem> q;
	q.push({ s, 0, 0 });
	while (!q.empty()) {
		auto now = q.front(); q.pop();
		if (visited[now.p.x][now.p.y][now.obj]) continue;
		visited[now.p.x][now.p.y][now.obj] = true;
		if (a[now.p.x][now.p.y] == 'E') {
			printf("");
		}
		if (a[now.p.x][now.p.y] == 'E' && now.obj == (1 << obj) - 1) {
			printf("%d", now.cnt);
			return 0;
		}
		if (a[now.p.x][now.p.y] == 'X') {
			now.obj |= mp[{now.p.x, now.p.y}];
		}
		now.cnt++;
		if (now.p.x && !visited[now.p.x - 1][now.p.y][now.obj]) {
			q.push({ {now.p.x - 1, now.p.y}, now.obj, now.cnt});
		}
		if (now.p.y && !visited[now.p.x][now.p.y - 1][now.obj]) {
			q.push({ {now.p.x, now.p.y - 1}, now.obj, now.cnt});
		}
		if (now.p.x < n - 1 && !visited[now.p.x + 1][now.p.y][now.obj]) {
			q.push({ {now.p.x + 1, now.p.y}, now.obj, now.cnt});
		}
		if (now.p.y < m - 1 && !visited[now.p.x][now.p.y + 1][now.obj]) {
			q.push({ {now.p.x, now.p.y + 1}, now.obj, now.cnt });
		}
	}
}