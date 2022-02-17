#include <iostream>
using namespace std;
struct uf {
	int *root;
	uf(int n) : root(new int[n * 2 + 3]) {
		for(int i = 1; i < n * 2 + 3; i++) root[i] = i;
	}
	int find(int a) {
		if(root[a] == a) return a;
		return root[a] = find(root[a]);
	}
	bool check(int a, int b) { return find(a) == find(b); }
	void merge(int a, int b) { root[find(a)] = find(b); }
};
int T(int n) { return n << 1; }
int F(int n) { return (n << 1) | 1; }
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n, m, i = 0;
	cin >> n >> m;
	uf u(n);
	for(; i < m; i++) {
		int x, y; char s[2];
		cin >> x >> y >> s;
		if(*s == 'T') {
			u.merge(T(x), T(y));
			u.merge(F(x), F(y));
		}
		else {
			u.merge(T(x), F(y));
			u.merge(F(x), T(y));
		}
		if(u.check(T(x), F(x))) goto PRT;
	}
PRT:cout << i;
}