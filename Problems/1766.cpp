#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;
int main() {
	int n, m;
	scanf("%d%d", &n, &m);

	auto v = new vector<int>[n + 1];
	auto d = new int[n + 1]();
	priority_queue<int> pq;

	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		v[a].push_back(b);
		d[b]++;
	}

	for (int i = 1; i <= n; i++) {
		if (d[i] == 0) {
			pq.push(-i);
		}
	}

	while (!pq.empty()) {
		auto const now = -pq.top(); pq.pop();
		printf("%d ", now);
		for (auto next : v[now]) {
			if (--d[next] == 0) {
				pq.push(-next);
			}
		}
	}

	delete[] v;
}