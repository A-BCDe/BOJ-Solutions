#include <stdio.h>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
int main() {
	int tt;
	scanf("%d", &tt);
	while (tt--) {
		int a, b;
		scanf("%d%d", &a, &b);
		auto v = new vector<int>[a + 1];
		for (int i = 0; i < b; i++) {
			int x, y;
			scanf("%d%d", &x, &y);
			v[x].push_back(y);
			v[y].push_back(x);
		}

		auto visited = new bool[a + 1]();
		auto even = new bool[a + 1]();

		for (int i = 1; i <= a; i++) {
			if (visited[i]) continue;
			visited[i] = true;
			even[i] = true;

			queue<pair<int, bool>> q; // node, even
			q.push(make_pair(i, true));

			while (!q.empty()) {
				auto const now = q.front();
				q.pop();
				if (visited[now.first]) {
					if (even[now.first] != now.second) {
						goto NO;
					}
				}
				visited[now.first] = true;
				even[now.first] = now.second;

				for (auto next : v[now.first]) {
					if (!visited[next]) q.push(make_pair(next, !now.second));
					else {
						if (even[next] == now.second) {
							goto NO;
						}
					}
				}
			}

		}

		printf("YES\n");
		goto END;
	NO:
		printf("NO\n");
		goto END;
	END:
		delete[] even;
		delete[] visited;
		delete[] v;
	}
}