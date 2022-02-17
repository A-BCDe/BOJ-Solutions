#include <algorithm>
#include <iostream>
using namespace std;
using ll = unsigned long long;
constexpr ll M = 1000000007;
struct uf {
	int n, cnt;
	int* root;
	uf(int n) : n(n), cnt(n), root(new int[n + 1]) {
		for (int i = 1; i <= n; i++) {
			root[i] = i;
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
		cnt--;
		root[x] = y;
	}
	bool check(int a, int b) { return find(a) == find(b); }
	int count() const { return cnt; }
};
inline void bell(ll *b, ll n) {
	b[0] = 1;
	auto c = new ll[n];
	fill(c, c + n, 1);
	for (int i = 0; i < n; i++) {
		b[i + 1] = (b[i + 1] + (b[i] * c[0]) % M) % M;
		for (int j = 1; j < n - i; j++) {
			b[i + j + 1] = (b[i + j + 1] + (b[i] * c[j]) % M) % M;
			c[j] = (c[j] + c[j - 1]) % M;
		}
	}
	delete[] c;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, m;
	cin >> n >> m;
	int x, y;
	uf u(n);
	auto b = new ll[n + 1]();
	bell(b, n);
	while (m--) {
		cin >> x >> y;
		u.merge(x, y);
		cout << b[u.count()] << '\n';
	}
}