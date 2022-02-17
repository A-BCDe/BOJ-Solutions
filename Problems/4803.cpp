#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, m, tt = 1;
	while (true) {
		cin >> n >> m;
		if (!n && !m) return 0;
		cout << "Case " << tt++ << ": ";
		auto v = new vector<int>[n + 1]();
		while (m--) {
			int x, y;
			cin >> x >> y;
			v[x].push_back(y);
			v[y].push_back(x);
		}
		auto visited = new bool[n + 1]();
		int res = 0;
		for (int i = 1; i <= n; i++) {
			if (!visited[i]) {
				bool flag = true;
				queue<pair<int, int>> q;
				q.push({ i, -1 });
				while (!q.empty()) {
					auto const now = q.front(); q.pop();
					if (visited[now.first]) {
						flag = false;
						continue;
					}
					visited[now.first] = true;
					for (auto next : v[now.first]) {
						if (next == now.second) continue;
						q.push({ next, now.first });
					}
				}
				res += flag;
			}
		}
		if (!res) {
			cout << "No trees.\n";
		}
		else if (res == 1) {
			cout << "There is one tree.\n";
		}
		else {
			cout << "A forest of " << res << " trees.\n";
		}
		delete[] visited;
		delete[] v;
	}
}