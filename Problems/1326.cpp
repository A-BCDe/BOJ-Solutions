#include <stdio.h>
#include <queue>
#include <utility>
using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	auto a = new int[n + 1];
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	int s, e;
	scanf("%d%d", &s, &e);
	auto visited = new bool[n + 1]();
	queue<pair<int, int>> q;
	q.push(make_pair(s, 0));
	while (!q.empty()) {
		auto const now = q.front(); q.pop();
		if (visited[now.first]) continue;
		visited[now.first] = true;
		if (now.first == e) {
			printf("%d", now.second);
			return 0;
		}
		for (int j = (now.first - 1) % a[now.first] + 1; j <= n; j += a[now.first]) {
			if (!visited[j]) q.push(make_pair(j, now.second + 1));
		}
	}
	printf("-1");
	delete[] visited;
	delete[] a;
}