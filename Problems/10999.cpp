#include <iostream>
#include <utility>
using namespace std;
using ll = long long;
inline ll calc(pair<ll, ll> const& p, int n) {
	return p.first + p.second * n;
}
ll init(pair<ll, ll>* t, ll const* a, int tidx, int l, int r) {
	if (l == r) {
		t[tidx].first = a[l];
		return a[l];
	}
	auto const m = (l + r) / 2;
	auto const x = init(t, a, tidx * 2, l, m);
	auto const y = init(t, a, tidx * 2 + 1, m + 1, r);
	t[tidx].first = x + y;
	return t[tidx].first;
}
ll update(pair<ll, ll>* t, int tidx, int start, int end, ll val, int l, int r) {
	if (end < l || r < start) return calc(t[tidx], r - l + 1);
	if (start <= l && r <= end) {
		t[tidx].second += val;
		return calc(t[tidx], r - l + 1);
	}
	auto const m = (l + r) / 2;
	if (t[tidx].second) {
		t[tidx * 2].second += t[tidx].second;
		t[tidx * 2 + 1].second += t[tidx].second;
		t[tidx].first = calc(t[tidx], r - l + 1);
		t[tidx].second = 0;
	}
	auto const x = update(t, tidx * 2, start, end, val, l, m);
	auto const y = update(t, tidx * 2 + 1, start, end, val, m + 1, r);
	t[tidx].first = x + y;
	return t[tidx].first;
}
ll sum(pair<ll, ll>* t, int tidx, int start, int end, int l, int r) {
	if (end < l || r < start) return 0;
	if (start <= l && r <= end) return calc(t[tidx], r - l + 1);
	auto const m = (l + r) / 2;
	if (t[tidx].second) {
		t[tidx * 2].second += t[tidx].second;
		t[tidx * 2 + 1].second += t[tidx].second;
		t[tidx].first = calc(t[tidx], r - l + 1);
		t[tidx].second = 0;
	}
	auto const x = sum(t, tidx * 2, start, end, l, m);
	auto const y = sum(t, tidx * 2 + 1, start, end, m + 1, r);
	return x + y;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, m, k;
	cin >> n >> m >> k;
	m += k;
	auto a = new ll[n + 1];
	auto t = new pair<ll, ll>[n * 4];
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	init(t, a, 1, 1, n);
	delete[] a;
	while (m--) {
		int w, x, y;
		cin >> w >> x >> y;
		if (w == 1) {
			ll z;
			cin >> z;
			update(t, 1, x, y, z, 1, n);
		}
		else {
			cout << sum(t, 1, x, y, 1, n) << '\n';
		}
	}
	delete[] t;
}