#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
struct uf {
	int const n;
	int* const root;
	int* const rank;
	uf(int n) : n(n), root(new int[n + 1]), rank(new int[n + 1]()) {
		for (int i = 1; i <= n; i++) {
			root[i] = i;
		}
	}
	~uf() { delete[] root; }
	int find(int a) {
		if (a == root[a]) return a;
		return root[a] = find(root[a]);
	}
	void merge(int a, int b) {
		int x = find(a);
		int y = find(b);
		if (x == y) return;
		if (rank[x] > rank[y]) swap(x, y);
		root[x] = y;
		if (rank[x] == rank[y]) rank[y]++;
	}
	bool check(int a, int b) { return find(a) == find(b); }
};
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, m, k;
	cin >> n >> m >> k;
	uf u(n);
	int prev, now;
	cin >> prev;
	for (int i = 1; i < k; i++) {
		cin >> now;
		u.merge(prev, now);
		prev = now;
	}
	priority_queue<pair<int, pair<int, int>>> pq;
	for (int i = 0; i < m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		pq.push({ -z, { x, y } });
	}
	long long res = 0;
	while (!pq.empty()) {
		auto const now = pq.top(); pq.pop();
		if (u.check(now.second.first, now.second.second)) continue;
		res -= now.first;
		u.merge(now.second.first, now.second.second);
	}
	cout << res;
}