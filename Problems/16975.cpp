#include <iostream>
#include <utility>
using namespace std;
using ll = long long;
inline ll calc(pair<ll, ll> const &p, ll n) {
	return p.first + p.second * n;
}
void init(pair<ll, ll> *t, ll const *a, ll tidx, ll l, ll r) {
	if(l == r) {
		t[tidx].first = a[l];
		t[tidx].second = 0;
		return;
	}
	auto const m = (l + r) >> 1;
	init(t, a, tidx * 2, l, m);
	init(t, a, tidx * 2 | 1, m + 1, r);
	t[tidx].first = t[tidx << 1].first + t[(tidx << 1) | 1].first;
	t[tidx].second = 0;
}
void update(pair<ll, ll> *t, ll tidx, ll start, ll end, ll val, ll l, ll r) {
	if(end < l || r < start) return;
	if(start <= l && r <= end) {
		t[tidx].second += val;
		return;
	}
	auto const m = (l + r) >> 1;
	if(t[tidx].second) {
		t[tidx].first = calc(t[tidx], r - l + 1);
		t[tidx << 1].second += t[tidx].second;
		t[(tidx << 1) | 1].second += t[tidx].second;
		t[tidx].second = 0;
	}
	update(t, tidx << 1, start, end, val, l, m);
	update(t, (tidx << 1) | 1, start, end, val, m + 1, r);
}
ll value(pair<ll, ll> *t, ll tidx, ll idx, ll l, ll r) {
	if(idx < l || r < idx) return 0;
	if(l == r) {
		return calc(t[tidx], 1);
	}
	auto const m = (l + r) >> 1;
	if(t[tidx].second) {
		t[tidx].first = calc(t[tidx], r - l + 1);
		t[tidx << 1].second += t[tidx].second;
		t[(tidx << 1) | 1].second += t[tidx].second;
		t[tidx].second = 0;
	}
	auto const x = value(t, tidx << 1, idx, l, m);
	auto const y = value(t, (tidx << 1) | 1, idx, m + 1, r);
	return x + y;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	ll n, m;
	cin >> n;
	auto a = new ll[n + 1];
	auto t = new pair<ll, ll>[n << 2];
	for(int i = 1; i <= n; i++) cin >> a[i];
	init(t, a, 1, 1, n);
	delete[] a;
	cin >> m;
	while(m--) {
		ll w, x;
		cin >> w >> x;
		if(w == 1) {
			ll y, z;
			cin >> y >> z;
			update(t, 1, x, y, z, 1, n);
		}
		else {
			cout << value(t, 1, x, 1, n) << '\n';
		}
	}
}