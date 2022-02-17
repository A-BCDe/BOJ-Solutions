#include <stdio.h>
int init(int* t, int const* a, int tidx, int l, int r) {
	if (l == r) return t[tidx] = l;
	auto const m = (l + r) / 2;
	auto const x = init(t, a, tidx * 2, l, m);
	auto const y = init(t, a, tidx * 2 + 1, m + 1, r);
	return t[tidx] = (a[x] <= a[y] ? x : y);
}
int update(int* t, int* a, int tidx, int idx, int val, int l, int r) {
	if (idx < l || idx > r) return t[tidx];
	if (l == r) {
		a[l] = val;
		return t[tidx] = l;
	}
	auto const m = (l + r) / 2;
	auto const x = update(t, a, tidx * 2, idx, val, l, m);
	auto const y = update(t, a, tidx * 2 + 1, idx, val, m + 1, r);
	return t[tidx] = (a[x] <= a[y] ? x : y);
}
int main() {
	int n;
	scanf("%d", &n);
	auto a = new int[n + 1];
	auto t = new int[n * 4]();
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	init(t, a, 1, 1, n);
	int m;
	scanf("%d", &m);
	while (m--) {
		int x;
		scanf("%d", &x);
		if (x == 1) {
			int y, z;
			scanf("%d%d", &y, &z);
			update(t, a, 1, y, z, 1, n);
		}
		else {
			printf("%d\n", t[1]);
		}
	}
}