#include <algorithm>
#include <iostream>
using namespace std;
struct node { int sum, left_max, right_max, max; };
node make_node(node const &left, node const &right) {
	node n;
	n.sum = left.sum + right.sum;
	n.left_max = max(left.left_max, left.sum + right.left_max);
	n.right_max = max(right.right_max, right.sum + left.right_max);
	n.max = max(max(left.max, right.max), left.right_max + right.left_max);
	return n;
}
void init(node *t, int const *a, int tidx, int u, int v, int l, int r) {
	if(l == r) {
		t[tidx].sum = t[tidx].left_max = t[tidx].right_max = t[tidx].max = u * a[l] + v;
		return;
	}
	auto const m = (l + r) / 2;
	init(t, a, tidx * 2, u, v, l, m);
	init(t, a, tidx * 2 + 1, u, v, m + 1, r);
	t[tidx] = make_node(t[tidx * 2], t[tidx * 2 + 1]);
}
void update(node *t, int tidx, int idx, int val, int l, int r) {
	if(idx < l || r < idx) return;
	if(l == r) {
		t[tidx].sum = t[tidx].left_max = t[tidx].right_max = t[tidx].max = val;
		return;
	}
	auto const m = (l + r) / 2;
	update(t, tidx * 2, idx, val, l, m);
	update(t, tidx * 2 + 1, idx, val, m + 1, r);
	t[tidx] = make_node(t[tidx * 2], t[tidx * 2 + 1]);
}
node sum(node const *t, int tidx, int start, int end, int l, int r) {
	if(end < l || r < start) return { 0, -1000000000, -1000000000, -1000000000 };
	if(start <= l && r <= end) return t[tidx];
	auto const m = (l + r) / 2;
	auto const x = sum(t, tidx * 2, start, end, l, m);
	auto const y = sum(t, tidx * 2 + 1, start, end, m + 1, r);
	return make_node(x, y);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, q, u, v;
	cin >> n >> q >> u >> v;
	auto a = new int[n + 1];
	auto t = new node[n * 4];
	for(int i = 1; i <= n; i++) cin >> a[i];
	init(t, a, 1, u, v, 1, n);
	delete[] a;
	while(q--) {
		int x, y, z;
		cin >> x >> y >> z;
		if(x) {
			update(t, 1, y, u * z + v, 1, n);
		}
		else {
			cout << sum(t, 1, y, z, 1, n).max - v << '\n';
		}
	}
}