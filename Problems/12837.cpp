#include <iostream>
using namespace std;
using ll = long long;
void update(ll* t, ll tidx, ll idx, ll val, ll l, ll r) {
	if (idx < l || r < idx) return;
	if (l == r) {
		t[tidx] += val;
		return;
	}
	auto const m = (l + r) / 2;
	update(t, tidx * 2, idx, val, l, m);
	update(t, tidx * 2 + 1, idx, val, m + 1, r);
	t[tidx] = t[tidx * 2] + t[tidx * 2 + 1];
}
ll sum(ll const* t, ll tidx, ll start, ll end, ll l, ll r) {
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
	ll n, q;
	cin >> n >> q;
	auto t = new ll[n << 2]();
	while (q--) {
		ll x, y, z;
		cin >> x >> y >> z;
		if (x == 1) update(t, 1, y, z, 1, n);
		else cout << sum(t, 1, y, z, 1, n) << '\n';
	}
}