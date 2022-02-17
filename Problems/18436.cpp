#include <iostream>
using namespace std;
int init(int* t, int* a, int tidx, int l, int r) {
	if (l == r) return t[tidx] = (a[l] & 1);
	auto const m = (l + r) / 2;
	auto const x = init(t, a, tidx * 2, l, m);
	auto const y = init(t, a, tidx * 2 + 1, m + 1, r);
	return t[tidx] = x + y;
}
int update(int* t, int tidx, int idx, int val, int l, int r) {
	if (idx < l || idx > r) return t[tidx];
	if (l == r) return t[tidx] = (val & 1);
	auto const m = (l + r) / 2;
	auto const x = update(t, tidx * 2, idx, val, l, m);
	auto const y = update(t, tidx * 2 + 1, idx, val, m + 1, r);
	return t[tidx] = x + y;
}
int sum(int const* t, int tidx, int start, int end, int l, int r) {
	if (end < l || r < start) return 0;
	if (start <= l && r <= end) return t[tidx];
	auto const m = (l + r) / 2;
	auto const x = sum(t, tidx * 2, start, end, l, m);
	auto const y = sum(t, tidx * 2 + 1, start, end, m + 1, r);
	return x + y;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, m;
	cin >> n;
	auto a = new int[n + 1];
	for (int i = 1; i <= n; i++) cin >> a[i];
	auto t = new int[n << 2]();
	init(t, a, 1, 1, n);
	delete[] a;
	cin >> m;
	while (m--) {
		int x, y, z;
		cin >> x >> y >> z;
		if (x == 1) {
			update(t, 1, y, z, 1, n);
			continue;
		}
		auto const odd = sum(t, 1, y, z, 1, n);
		if (x == 2) cout << z - y + 1 - odd << '\n';
		else cout << odd << '\n';
	}
	delete[] t;
}