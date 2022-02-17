#include <stdio.h>
#include <vector>
using namespace std;
struct uf {
	int n;
	int *root;
	uf(int n) : n(n), root(new int[n + 1]) {
		for(int i = 1; i <= n; i++) root[i] = i;
	}
	int find(int a) {
		if(a == root[a]) return a;
		return root[a] = find(root[a]);
	}
	void merge(int a, int b) {
		int x = find(a);
		int y = find(b);
		if(x == y) return;
		root[x] = y;
	}
	bool check(int a, int b) { return find(a) == find(b); }
};
int main() {
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	uf u(n);
	auto know = new int[k];
	for(int i = 0; i < k; i++) {
		scanf("%d", know + i);
	}
	vector<vector<int>> party;
	for(int i = 0; i < m; i++) {
		int l, x, y;
		party.emplace_back();
		scanf("%d", &l);
		scanf("%d", &x);
		party.back().emplace_back(x);
		for(int j = 1; j < l; j++) {
			scanf("%d", &y);
			u.merge(x, y);
			x = y;
			party.back().emplace_back(x);
		}
	}
	int cnt = 0;
	for(auto const &v : party) {
		bool flag = false;
		for(auto i : v) {
			for(int j = 0; j < k; j++) {
				if(u.check(i, know[j])) {
					flag = true;
					break;
				}
			}
			if(flag) break;
		}
		if(!flag) cnt++;
	}
	printf("%d", cnt);
}