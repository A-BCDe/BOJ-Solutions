#include <stdio.h>
using ll = long long;
ll init(ll* t, ll* a, int tidx, int l, int r) {
	if (l == r) return t[tidx] = l;
	auto const m = (l + r) / 2;
	auto const x = init(t, a, tidx * 2, l, m);
	auto const y = init(t, a, tidx * 2 + 1, m + 1, r);
	return t[tidx] = (a[x] < a[y] ? x : y);
}
ll mini(ll* t, ll* a, int tidx, int start, int end, int l, int r) {
	if (r < start || l > end) return 0;
	if (start <= l && r <= end) return t[tidx];
	auto const m = (l + r) / 2;
	auto const x = mini(t, a, tidx * 2, start, end, l, m);
	auto const y = mini(t, a, tidx * 2 + 1, start, end, m + 1, r);
	if (!x) return y;
	if (!y) return x;
	return a[x] > a[y] ? y : x;
}
ll f(ll* t, ll* a, int n, int l, int r) {
	if (l > r) return 0;
	if (l == r) return a[l];
	auto const idx = mini(t, a, 1, l, r, 1, n);
	auto size = a[idx] * (r - l + 1);
	auto const x = f(t, a, n, l, idx - 1);
	auto const y = f(t, a, n, idx + 1, r);
	if (size < x) size = x;
	if (size < y) size = y;
	return size;
}
int main() {
	int n;
	while (true) {
		scanf("%d", &n);
		if (n == 0) break;
		auto a = new ll[n + 1];
		auto t = new ll[n * 4]();
		for (int i = 1; i <= n; i++) {
			scanf("%lld", &a[i]);
		}
		init(t, a, 1, 1, n);
		printf("%lld\n", f(t, a, n, 1, n));
		delete[] t;
		delete[] a;
	}
}