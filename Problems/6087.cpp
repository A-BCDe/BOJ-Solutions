#include <stdio.h>
#include <queue>
#include <utility>
using namespace std;
int main() {
	int w, h;
	scanf("%d%d", &w, &h);
	auto a = new char* [w];
	bool flag = false;
	pair<int, int> start, end;
	bool** visited[2];
	visited[0] = new bool* [w]; // up
	visited[1] = new bool* [w]; // left
	for (int i = 0; i < w; i++) {
		a[i] = new char[h + 1];
		visited[0][i] = new bool[h]();
		visited[1][i] = new bool[h]();
		scanf("%s", a[i]);
		for (int j = 0; j < h; j++) {
			if (a[i][j] == 'C') {
				if(flag) end = make_pair(i, j);
				else { start = make_pair(i, j); flag = true; }
			}
		}
	}
	queue<pair<pair<int, int>, pair<int, int>>> q; // cnt, dir, x, y
	q.push(make_pair(make_pair(0, 0), start));
	q.push(make_pair(make_pair(0, 1), start));
	while (!q.empty()) {
		auto const now = q.front(); q.pop();
		if (visited[now.first.second][now.second.first][now.second.second]) continue;
		visited[now.first.second][now.second.first][now.second.second] = true;
		if (now.first.second) { // left right
			for (int i = 1; now.second.second + i < h && a[now.second.first][now.second.second + i] != '*'; i++) {
				
			}
		}
		else { // up down

		}
	}
}