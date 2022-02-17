#include <algorithm>
#include <stdio.h>
using ll = long long;
ll sum(ll const* t, int tidx, ll start, ll end, ll l, ll r) {
	if (end < l || r < start) return 0;
	if (start <= l && r <= end) return t[tidx];
	auto const m = (l + r) / 2;
	auto const x = sum(t, tidx * 2, start, end, l, m);
	auto const y = sum(t, tidx * 2 + 1, start, end, m + 1, r);
	return x + y;
}
ll update(ll* t, int tidx, ll idx, ll val, ll l, ll r) {
	if (idx < l || r < idx) return t[tidx];
	if (l == r) return t[tidx] = val;
	auto const m = (l + r) / 2;
	auto const x = update(t, tidx * 2, idx, val, l, m);
	auto const y = update(t, tidx * 2 + 1, idx, val, m + 1, r);
	return t[tidx] = x + y;
}
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	auto t = new ll[n << 2]();
	while (m--) {
		ll x, y, z;
		scanf("%lld%lld%lld", &x, &y, &z);
		if (!x) {
			if (y > z) std::swap(y, z);
			printf("%lld\n", sum(t, 1, y, z, 1, n));
		}
		else update(t, 1, y, z, 1, n);
	}
	delete[] t;
}