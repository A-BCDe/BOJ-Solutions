#include <stdio.h>
#include <queue>
#include <vector>
#include <utility>
using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	auto v = new vector<int>[n + 1];
	auto a = new int[n + 1];
	auto d = new int[n + 1]();
	priority_queue<pair<int, int>> q;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		int x;
		while (true) {
			scanf("%d", &x);
			if (x == -1) {
				if (d[i] == 0) {
					q.push(make_pair(-a[i], i));
				}
				break;
			}
			v[x].push_back(i);
			d[i]++;
		}
	}
	auto res = new int[n + 1];
	while (!q.empty()) {
		auto const now = q.top(); q.pop();
		res[now.second] = -now.first;
		for (auto next : v[now.second]) {
			if (--d[next] == 0) {
				q.push(make_pair(now.first - a[next], next));
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		printf("%d\n", res[i]);
	}
	delete[] d;
	delete[] res;
	delete[] a;
	delete[] v;
}