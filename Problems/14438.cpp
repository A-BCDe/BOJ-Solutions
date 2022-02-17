#include <stdio.h>
int init(int* t, int* a, int tidx, int l, int r) {
	// left node : tidx * 2
	// right node : tidx * 2 + 1
	if (l == r) return t[tidx] = a[l];
	auto const m = (l + r) / 2;
	auto const left = init(t, a, tidx * 2, l, m);
	auto const right = init(t, a, tidx * 2 + 1, m + 1, r);
	return t[tidx] = (left < right ? left : right);
}
int update(int* t, int* a, int tidx, int y, int z, int l, int r) {
	if (y < l || y > r) return t[tidx];
	if (l == r) return t[tidx] = a[y] = z;
	auto const m = (l + r) / 2;
	auto const left = update(t, a, tidx * 2, y, z, l, m);
	auto const right = update(t, a, tidx * 2 + 1, y, z, m + 1, r);
	return t[tidx] = (left < right ? left : right);
}
int min(int* t, int* a, int tidx, int start, int end, int l, int r) {
	if (r < start || l > end) return 1000000001;
	if (start <= l && r <= end) return t[tidx];
	auto const m = (l + r) / 2;
	auto const left = min(t, a, tidx * 2, start, end, l, m);
	auto const right = min(t, a, tidx * 2 + 1, start, end, m + 1, r);
	return left < right ? left : right;
}
int main() {
	int n;
	scanf("%d", &n);
	auto a = new int[n + 1]; // val
	auto t = new int[n * 4](); // tree
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
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
		else {
			printf("%d\n", min(t, a, 1, y, z, 1, n));
		}
	}
	delete[] t;
	delete[] a;
}