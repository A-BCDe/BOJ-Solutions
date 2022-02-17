#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;
int main() {
	int tt;
	scanf("%d", &tt);
	while (tt--) {
		int n, k, w;
		scanf("%d%d", &n, &k);
		auto d = new int[n + 1];
		for (int i = 1; i <= n; i++) {
			scanf("%d", &d[i]);
		}
		auto v = new vector<int>[n + 1];
		auto deg = new int[n + 1]();
		for (int i = 0; i < k; i++) {
			int x, y;
			scanf("%d%d", &x, &y);
			v[x].push_back(y);
			deg[y]++;
		}
		scanf("%d", &w);
		priority_queue<pair<int, int>> pq;
		for (int i = 1; i <= n; i++) {
			if (!deg[i]) {
				pq.push({ -d[i], i });
			}
		}
		while (!pq.empty()) {
			auto const now = pq.top(); pq.pop();
			if (deg[now.second]) continue;
			if (now.second == w) {
				printf("%d\n", -now.first);
				break;
			}
			for (auto next : v[now.second]) {
				deg[next]--;
				if (!deg[next]) {
					pq.push({ now.first - d[next], next });
				}
			}
		}
		delete[] d;
		delete[] deg;
		delete[] v;
	}
}