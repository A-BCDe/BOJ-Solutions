#include <queue>
#include <stdio.h>
#include <utility>
using namespace std;
int main() {
	int n;
	int t = 1;
	while (true) {
		scanf("%d", &n);
		if (!n) return 0;
		printf("Problem %d: ", t++);
		auto a = new int*[n];
		auto visited = new bool* [n];
		for (int i = 0; i < n; i++) {
			a[i] = new int[n];
			visited[i] = new bool[n]();
			for (int j = 0; j < n; j++) {
				scanf("%d", &a[i][j]);
			}
		}
		priority_queue<pair<int, pair<int, int>>> pq;
		pq.push({ -a[0][0], {0, 0} });
		while (!pq.empty()) {
			auto const now = pq.top(); pq.pop();
			if (visited[now.second.first][now.second.second]) continue;
			visited[now.second.first][now.second.second] = true;
			if (now.second.first == n - 1 && now.second.second == n - 1) {
				printf("%d\n", -now.first);
				break;
			}
			if (now.second.first && !visited[now.second.first - 1][now.second.second]) {
				pq.push({ now.first - a[now.second.first - 1][now.second.second], {now.second.first - 1, now.second.second} });
			}
			if (now.second.second && !visited[now.second.first][now.second.second - 1]) {
				pq.push({ now.first - a[now.second.first][now.second.second - 1], {now.second.first, now.second.second - 1} });
			}
			if (now.second.first < n - 1 && !visited[now.second.first + 1][now.second.second]) {
				pq.push({ now.first - a[now.second.first + 1][now.second.second], {now.second.first + 1, now.second.second} });
			}
			if (now.second.second < n - 1 && !visited[now.second.first][now.second.second + 1]) {
				pq.push({ now.first - a[now.second.first][now.second.second + 1], {now.second.first, now.second.second + 1} });
			}
		}
		for (int i = 0; i < n; i++) {
			delete[] a[i];
		} delete[] a;
	}
}