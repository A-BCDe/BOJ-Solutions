#include <cstdio>
#include <cstring>
using ll = long long;
ll update(ll* t, ll* b, int tidx, int dest, ll val, int l, int r) {
	if (dest < l || dest > r) return t[tidx];
	if (l == r) return t[tidx] = b[l] = val;
	auto const m = (l + r) / 2;
	auto const x = update(t, b, tidx * 2, dest, val, l, m);
	auto const y = update(t, b, tidx * 2 + 1, dest, val, m + 1, r);
	return t[tidx] = (x > y ? x : y);
}
ll max(ll* t, ll* b, int tidx, int start, int end, int l, int r) {
	if (r < start || end < l) return -1000000001;
	if (start <= l && r <= end) return t[tidx];
	auto const m = (l + r) / 2;
	auto const x = max(t, b, tidx * 2, start, end, l, m);
	auto const y = max(t, b, tidx * 2 + 1, start, end, m + 1, r);
	return x > y ? x : y;
}
int main() {
	int n, d;
	scanf("%d%d", &n, &d);
	auto a = new ll[n + 1];
	auto b = new ll[n + 1]();
	auto t = new ll[n * 4]();
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	update(t, b, 1, n, a[n], 1, n);
	for (int i = n - 1; i; i--) {
		auto const m = max(t, b, 1, i + 1, (i + d < n ? i + d : n), 1, n);
		update(t, b, 1, i, (m < 0 ? a[i] : (a[i] + m)), 1, n);
	}
	printf("%lld", max(t, b, 1, 1, n, 1, n));
	delete[] b;
	delete[] t;
	delete[] a;
}