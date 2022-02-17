#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
constexpr int64_t M = 1000000001;
void init(vector<int>* t, int const* a, int tidx, int l, int r) {
	if (l == r) {
		t[tidx].push_back(a[l]);
		return;
	}
	auto const m = (l + r) / 2;
	init(t, a, tidx * 2, l, m);
	init(t, a, tidx * 2 + 1, m + 1, r);
	t[tidx].resize(r - l + 1);
	merge(t[tidx * 2].begin(), t[tidx * 2].end(), t[tidx * 2 + 1].begin(), t[tidx * 2 + 1].end(), t[tidx].begin());
}
int64_t count(vector<int>* t, int tidx, int start, int end, int val, int l, int r) {
	if (end < l || r < start) return -M;
	if (start <= l && r <= end) return upper_bound(t[tidx].begin(), t[tidx].end(), val) - t[tidx].begin();
	auto const m = (l + r) / 2;
	auto const x = count(t, tidx * 2, start, end, val, l, m);
	auto const y = count(t, tidx * 2 + 1, start, end, val, m + 1, r);
	if (x == -M) return y;
	if (y == -M) return x;
	return x + y;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, m; cin >> n >> m;
	auto a = new int[n + 1];
	auto t = new vector<int>[n * 4];
	for (int i = 1; i <= n; i++) cin >> a[i];
	init(t, a, 1, 1, n);
	delete[] a;
	while (m--) {
		int x, y, z;
		cin >> x >> y >> z;
		int64_t l = t[1][0], r = t[1].back() + (int64_t)1;
		while (l < r) {
			auto const m = (l + r + (M << 1)) / 2 - M;
			auto const res = count(t, 1, x, y, m, 1, n);
			if (res < z) l = m + 1;
			else r = m;
		}
		cout << r << '\n';
	}
	delete[] t;
}