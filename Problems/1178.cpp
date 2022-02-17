#include <stdio.h>
#include <algorithm>
#include <memory>
#include <queue>
#include <vector>
using namespace std;
struct uf {
	int* rank, * root;
	uf(int n) : root(new int[n + 1]), rank(new int[n + 1]) {
		for (int i = 1; i <= n; i++) {
			root[i] = i;
			rank[i] = 1;
		}
	}
	int find(int a) {
		if (root[a] == a) return a;
		return root[a] = find(root[a]);
	}
	void merge(int a, int b) {
		int x = find(a);
		int y = find(b);
		if (x == y) return;
		if (rank[x] > rank[y]) swap(x, y);
		root[x] = y;
		if (rank[x] == rank[y]) rank[x]++;
	}
	bool check(int a, int b) { return find(a) == find(b); }
};
int find_odd(vector<int>* v, int const* deg, int n, int a) {
	queue<int> q;
	q.push(a);
	auto visited = make_unique<bool[]>(n + 1);
	while (!q.empty()) {
		auto const now = q.front(); q.pop();
		if (visited[now]) continue;
		visited[now] = true;
		if (deg[now] & 1) return now;
		for (auto next : v[now]) {
			if (!visited[next]) q.push(next);
		}
	}
	return 0;
}
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	auto v = new vector<int>[n + 1];
	auto deg = new int[n + 1]();
	uf u(n);
	while (m--) {
		int a, b;
		scanf("%d%d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
		u.merge(a, b);
		deg[a]++;
		deg[b]++;
	}
	int cnt = 0;
	for (int i = 1; i < n; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (!u.check(i, j)) {
				auto x = find_odd(v, deg, n, i);
				auto y = find_odd(v, deg, n, j);
				if (!x) x = i;
				if (!y) y = j;
				v[x].push_back(y);
				v[y].push_back(x);
				u.merge(x, y);
				deg[x]++;
				deg[y]++;
				cnt++;
			}
		}
	}
	int odd = 0;
	vector<int> oddv;
	for (int i = 1; i <= n; i++) {
		odd += (deg[i] & 1);
	}
	if (odd > 2) {
		cnt += (odd - 2) >> 1;
	}
	printf("%d", cnt);
	delete[] deg;
	delete[] v;
}