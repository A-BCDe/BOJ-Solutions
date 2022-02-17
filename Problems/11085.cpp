#include <iostream>
#include <queue>
#include <vector>
using std::cin;
using std::cout;
using std::ios_base;
struct str {
	int start, end, width;
	bool operator()(str const& a, str const& b) {
		return a.width < b.width;
	}
};
struct uf {
	int const n;
	int* const root;
	int* const rank;
	uf(int n) : n(n), root(new int[n]), rank(new int[n]()) {
		for (int i = 0; i < n; i++) {
			root[i] = i;
		}
	}
	~uf() { delete[] root; }
	int find(int a) {
		if (root[a] == a) return a;
		return root[a] = find(root[a]);
	}
	void merge(int a, int b) {
		int x = find(a);
		int y = find(b);
		if (x == y) return;
		if (rank[x] > rank[y]) std::swap(x, y);
		root[x] = y;
		rank[y] += (rank[x] == rank[y]);
	}
	bool check(int a, int b) { return find(a) == find(b); }
};
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int p, w, c, v;
	cin >> p >> w >> c >> v;
	std::priority_queue<str, std::vector<str>, str> pq;
	while (w--) {
		int x, y, z;
		cin >> x >> y >> z;
		pq.push({ x, y, z });
	}
	uf u(p);
	while (!pq.empty()) {
		auto const now = pq.top(); pq.pop();
		u.merge(now.start, now.end);
		if (u.check(c, v)) {
			printf("%d", now.width);
			return 0;
		}
	}
}