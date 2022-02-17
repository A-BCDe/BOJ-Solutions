#include <stdio.h>
using ll = long long;
int init(int* t, ll const* a, int tidx, int l, int r) {
	if (l == r) return t[tidx] = l;
	auto const m = (l + r) / 2;
	auto const x = init(t, a, tidx * 2, l, m);
	auto const y = init(t, a, tidx * 2 + 1, m + 1, r);
	return t[tidx] = (a[x] < a[y] ? x : y);
}
int mini(int const* t, ll const* a, int tidx, int start, int end, int l, int r) {
	if (r < start || end < l) return 0;
	if (start <= l && r <= end) return t[tidx];
	auto const m = (l + r) / 2;
	auto const x = mini(t, a, tidx * 2, start, end, l, m);
	auto const y = mini(t, a, tidx * 2 + 1, start, end, m + 1, r);
	if (!x) return y;
	if (!y) return x;
	return a[x] < a[y] ? x : y;
}
ll f(int const* t, ll const* a, int n, int l, int r) {
	if (l > r) return 0;
	auto const m = mini(t, a, 1, l, r, 1, n);
	auto res = ((ll)r - l + 1) * a[m];
	auto const x = f(t, a, n, l, m - 1);
	auto const y = f(t, a, n, m + 1, r);
	if (res < x) res = x;
	if (res < y) res = y;
	return res;
}
int main() {
	int n;
	scanf("%d", &n);
	auto a = new ll[n + 1];
	auto t = new int[n * 4]();
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	init(t, a, 1, 1, n);
	printf("%lld", f(t, a, n, 1, n));
}