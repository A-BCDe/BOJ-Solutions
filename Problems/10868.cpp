#include <stdio.h>
int init(int* t, int const* a, int tidx, int l, int r) {
	if (l == r) return t[tidx] = a[l];
	auto const m = (l + r) / 2;
	auto const x = init(t, a, tidx * 2, l, m);
	auto const y = init(t, a, tidx * 2 + 1, m + 1, r);
	return t[tidx] = (x > y ? y : x);
}
int min(int const* t, int const* a, int tidx, int start, int end, int l, int r) {
	if (r < start || end < l) return 1000000001;
	if (start <= l && r <= end) return t[tidx];
	auto const m = (l + r) / 2;
	auto const x = min(t, a, tidx * 2, start, end, l, m);
	auto const y = min(t, a, tidx * 2 + 1, start, end, m + 1, r);
	return x < y ? x : y;
}
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	auto a = new int[n + 1];
	auto t = new int[n * 4]();
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	init(t, a, 1, 1, n);
	while (m--) {
		int x, y;
		scanf("%d%d", &x, &y);
		printf("%d\n", min(t, a, 1, x, y, 1, n));
	}
}