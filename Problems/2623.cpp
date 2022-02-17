#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	auto d = new int[n + 1]();
	auto v = new vector<int>[n + 1];
	auto q = new queue<int>[m];
	for (int i = 0; i < m; i++) {
		int a;
		scanf("%d", &a);
		int prev;
		for (int j = 0; j < a; j++) {
			int x;
			scanf("%d", &x);
			if (j > 0) {
				v[prev].push_back(x);
				d[x]++;
			}
			q[i].push(x);
			prev = x;
		}
	}
	auto visited = new bool[n + 1]();
	int cnt = 0;
	int flag = 0;
	vector<int> res;
	for(int i = 0; cnt < m && flag < m; i = (i + 1) % m) {
		if (q[i].empty()) { flag++; continue; }
		// printf("front = %d, d = %d, cnt = %d\n", q[i].front(), d[q[i].front()], cnt);
		flag = 0;
		if (d[q[i].front()]) { cnt++; continue; }
		if (visited[q[i].front()]) { q[i].pop(); cnt = 0; continue; }
		visited[q[i].front()] = true;
		cnt = 0;
		auto const now = q[i].front();
		q[i].pop();
		res.push_back(now);
		for (auto const next : v[now]) {
			d[next]--;
		}
	}
	if (cnt == m) {
		printf("0");
	}
	else {
		for (auto now : res) {
			printf("%d\n", now);
		}
		for (int i = 1; i <= n; i++) {
			if (!visited[i]) printf("%d\n", i);
		}
	}
	delete[] d;
	delete[] v;
	delete[] q;
}