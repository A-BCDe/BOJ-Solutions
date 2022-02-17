#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
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
ll count(vector<int> const* t, int tidx, int start, int end, int val, int l, int r) {
	if (end < l || r < start) return 0;
	if (start <= l && r <= end) return t[tidx].end() - upper_bound(t[tidx].begin(), t[tidx].end(), val);
	auto const m = (l + r) / 2;
	auto const x = count(t, tidx * 2, start, end, val, l, m);
	auto const y = count(t, tidx * 2 + 1, start, end, val, m + 1, r);
	return x + y;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, m;
	cin >> n;
	auto a = new int[n + 1]();
	auto t = new vector<int>[n * 4];
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	init(t, a, 1, 1, n);
	delete[] a;
	cin >> m;
	while (m--) {
		int x, y, z;
		cin >> x >> y >> z;
		cout << count(t, 1, x, y, z, 1, n) << '\n';
	}
	delete[] t;
}