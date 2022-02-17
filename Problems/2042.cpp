#include <stdio.h>
using ll = long long;
ll init(ll* t, ll* a, int tidx, int left, int right) {
	if (left == right) return t[tidx] = a[left];
	auto const m = (left + right) / 2;
	auto const x = init(t, a, tidx * 2, left, m);
	auto const y = init(t, a, tidx * 2 + 1, m + 1, right);
	return t[tidx] = x + y;
}
ll update(ll* t, ll* a, int tidx, ll b, ll c, ll left, ll right) {
	if (b < left || right < b) return t[tidx];
	if (left == right) {
		a[b] = c;
		return t[tidx] = c;
	}
	auto const m = (left + right) / 2;
	auto const x = update(t, a, tidx * 2, b, c, left, m);
	auto const y = update(t, a, tidx * 2 + 1, b, c, m + 1, right);
	return t[tidx] = x + y;
}
ll sum(ll* t, ll* a, int tidx, ll b, ll c, ll left, ll right) {
	if (c < left || right < b) return 0;
	if (b <= left && right <= c) return t[tidx];
	auto const m = (left + right) / 2;
	auto const x = sum(t, a, tidx * 2, b, c, left, m);
	auto const y = sum(t, a, tidx * 2 + 1, b, c, m + 1, right);
	return x + y;
}
int main() {
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	m += k;
	auto a = new ll[n + 1];
	auto t = new ll[n * 4]();
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	init(t, a, 1, 1, n);
	for (int i = 0; i < m; i++) {
		ll x, y, z;
		scanf("%lld%lld%lld", &x, &y, &z);
		if (x == 1) {
			update(t, a, 1, y, z, 1, n);
		}
		else if (x == 2) {
			printf("%lld\n", sum(t, a, 1, y, z, 1, n));
		}
	}
}