#include <stdio.h>
int init(int* t, int* a, int tidx, int left, int right) {
	if (left == right) return t[tidx] = left;
	auto const m = (left + right) / 2;
	auto const x = init(t, a, tidx * 2, left, m);
	auto const y = init(t, a, tidx * 2 + 1, m + 1, right);
	return t[tidx] = (a[x] <= a[y] ? x : y);
}
int update(int* t, int* a, int tidx, int y, int z, int left, int right) {
	if (y < left || right < y) return t[tidx];
	if (left == right) {
		a[left] = z;
		return t[tidx] = left;
	}
	auto const m = (left + right) / 2;
	auto const l = update(t, a, tidx * 2, y, z, left, m);
	auto const r = update(t, a, tidx * 2 + 1, y, z, m + 1, right);
	return t[tidx] = (a[l] <= a[r] ? l : r);
}
int min(int* t, int* a, int tidx, int start, int end, int left, int right) {
	if (end < left || right < start) return 0;
	if (start <= left && right <= end) return t[tidx];
	auto const m = (left + right) / 2;
	auto const l = min(t, a, tidx * 2, start, end, left, m);
	auto const r = min(t, a, tidx * 2 + 1, start, end, m + 1, right);
	if (!l) return r;
	if (!r) return l;
	return a[l] <= a[r] ? l : r;
}
int main() {
	int n;
	scanf("%d", &n);
	auto a = new int[n + 1];
	auto t = new int[n * 4];
	for (int i = 1; i <= n; i++) {
		scanf("%d", a + i);
	}
	init(t, a, 1, 1, n);
	int m;
	scanf("%d", &m);
	while (m--) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		if (x == 1) {
			update(t, a, 1, y, z, 1, n);
		}
		if (x == 2) {
			printf("%d\n", min(t, a, 1, y, z, 1, n));
		}
	}
}