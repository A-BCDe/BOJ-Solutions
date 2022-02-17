#include <stdio.h>
#include <queue>
#include <vector>
#include <utility>
using namespace std;
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	auto v = new vector<pair<int, int>>[n + 1];
	for (int i = 0; i < m; i++) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		v[a].emplace_back(-c, b);
		v[b].emplace_back(-c, a);
	}
	for (int i = 1; i <= n; i++) {
		auto arr = new int[n + 1]();
		arr[i] = -1;
		priority_queue<pair<int, pair<int, int>>> pq;
		for (auto&& now : v[i]) {
			pq.push(make_pair(now.first, make_pair(now.second, now.second)));
		}
		while (!pq.empty()) {
			auto const now = pq.top(); pq.pop();
			if (arr[now.second.second]) continue;
			arr[now.second.second] = now.second.first;
			for (auto const& next : v[now.second.second]) {
				if (!arr[next.second]) {
					pq.push(make_pair(now.first + next.first, make_pair(now.second.first, next.second)));
				}
			}
		}
		for (int j = 1; j <= n; j++) {
			if (j == i) printf("- ");
			else printf("%d ", arr[j]);
		}
		printf("\n");
		delete[] arr;
	}
	delete[] v;
}