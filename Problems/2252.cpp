#include <stdio.h>
#include <stack>
#include <vector>
using namespace std;
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	auto v = new vector<int>[n + 1];
	auto d = new int[n + 1]();
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		v[a].push_back(b);
		d[b]++;
	}
	stack<int> s;
	for (int i = 1; i <= n; i++) {
		if (d[i] == 0) s.push(i);
	}
	while (!s.empty()) {
		auto const now = s.top(); s.pop();
		printf("%d ", now);
		for (auto const next : v[now]) {
			if (--d[next] == 0) s.push(next);
		}
	}
}