#include <stdio.h>
using ll = long long;
ll init(ll* t, ll* a, ll tidx, ll left, ll right) {
	if (left == right) return t[tidx] = a[left];
	auto const m = (left + right) / 2;
	auto const x = init(t, a, tidx * 2, left, m);
	auto const y = init(t, a, tidx * 2 + 1, m + 1, right);
	return t[tidx] = x + y;
}
ll sum(ll* t, ll* a, ll tidx, ll start, ll end, ll left, ll right) {
	if (end < left || right < start) return 0;
	if (start <= left && right <= end) return t[tidx];
	auto const m = (left + right) / 2;
	auto const x = sum(t, a, tidx * 2, start, end, left, m);
	auto const y = sum(t, a, tidx * 2 + 1, start, end, m + 1, right);
	return x + y;
}
ll update(ll* t, ll* a, ll tidx, ll x, ll y, ll left, ll right) {
	if (x < left || right < x) return t[tidx];
	if (left == right) {
		a[left] = y;
		return t[tidx] = y;
	}
	auto const m = (left + right) / 2;
	auto const l = update(t, a, tidx * 2, x, y, left, m);
	auto const r = update(t, a, tidx * 2 + 1, x, y, m + 1, right);
	return t[tidx] = l + r;
}
int main() {
	int n, q;
	scanf("%d%d", &n, &q);
	auto a = new ll[n + 1];
	auto t = new ll[n * 4]();
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	init(t, a, 1, 1, n);
	for (int i = 0; i < q; i++) {
		long long x, y;
		scanf("%lld%lld", &x, &y);
		if (y < x) {
			auto tmp = x;
			x = y;
			y = tmp;
		}
		printf("%lld\n", sum(t, a, 1, x, y, 1, n));
		scanf("%lld%lld", &x, &y);
		update(t, a, 1, x, y, 1, n);
	}
}