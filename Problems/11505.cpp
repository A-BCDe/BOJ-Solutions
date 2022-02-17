#include <iostream>
using namespace std;
using ll = long long;
constexpr ll M = 1000000007;
ll init(ll* t, ll const* a, int tidx, int l, int r) {
	if (l == r) return t[tidx] = a[l];
	auto const m = (l + r) / 2;
	auto const x = init(t, a, tidx * 2, l, m);
	auto const y = init(t, a, tidx * 2 + 1, m + 1, r);
	return t[tidx] = (x * y) % M;
}
ll update(ll* t, int tidx, int idx, int val, int l, int r) {
	if (idx < l || idx > r) return t[tidx];
	if (l == r) return t[tidx] = val;
	auto const m = (l + r) / 2;
	auto const x = update(t, tidx * 2, idx, val, l, m);
	auto const y = update(t, tidx * 2 + 1, idx, val, m + 1, r);
	return t[tidx] = (x * y) % M;
}
ll mul(ll const* t, int tidx, int start, int end, int l, int r) {
	if (end < l || r < start) return 1;
	if (start <= l && r <= end) return t[tidx];
	auto const m = (l + r) / 2;
	auto const x = mul(t, tidx * 2, start, end, l, m);
	auto const y = mul(t, tidx * 2 + 1, start, end, m + 1, r);
	return (x * y) % M;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, m, k;
	cin >> n >> m >> k;
	m += k;
	auto a = new ll[n + 1];
	auto t = new ll[n * 4];
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	init(t, a, 1, 1, n);
	delete[] a;
	while (m--) {
		int x, y, z;
		cin >> x >> y >> z;
		if (x == 1) {
			update(t, 1, y, z, 1, n);
		}
		else {
			cout << mul(t, 1, y, z, 1, n) << '\n';
		}
	}
	delete[] t;
}