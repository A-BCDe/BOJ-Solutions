#include <stdio.h>
struct uf {
	int* root;
	uf(int n) : root(new int[n + 1]) {
		for (int i = 0; i <= n; i++) {
			root[i] = i;
		}
	}
	int find(int x) {
		if (root[x] == x) return x;
		return root[x] = find(root[x]);
	}
	void merge(int a, int b) {
		auto x = find(a);
		auto y = find(b);
		if (x == y) return;
		root[x] = y;
	}
	bool check(int a, int b) {
		return find(a) == find(b);
	}
};
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	uf u(n);
	while (m--) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		if (!x) {
			u.merge(y, z);
		}
		else {
			printf(u.check(y, z) ? "YES\n" : "NO\n");
		}
	}
}