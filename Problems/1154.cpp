#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <vector>
#include <utility>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin >> n;
	auto team = new int[n + 1]();
	auto a = new bool* [n + 1];
	for (int i = 1; i <= n; i++) {
		a[i] = new bool[n + 1]();
	}
	while (true) {
		int x, y;
		cin >> x >> y;
		if (x == -1 && y == -1) break;
		a[x][y] = a[y][x] = true;
	}
	for (int i = 1; i <= n; i++) {
		if (!team[i]) {
			queue<pair<int, int>> q;
			q.push({ i, 1 });
			while (!q.empty()) {
				auto const now = q.front(); q.pop();
				if (team[now.first] != 0) {
					if (team[now.first] != now.second) {
						printf("-1");
						return 0;
					}
					continue;
				}
				team[now.first] = now.second;
				for (int i = 1; i <= n; i++) {
					if (now.first == i) continue;
					if (!a[now.first][i]) {
						q.push({ i, -now.second });
					}
				}
			}
		}
	}
	printf("1\n");
	for (int i = 1; i <= n; i++) {
		if (team[i] == 1) printf("%d ", i);
	} printf("-1\n");
	for (int i = 1; i <= n; i++) {
		if (team[i] == -1) printf("%d ", i);
	} printf("-1");
	delete[] team;
	for (int i = 1; i <= n; i++) {
		delete[] a[i];
	}
	delete[] a;
}