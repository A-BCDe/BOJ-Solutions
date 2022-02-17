#include <stdio.h>
int init(int* t, int* a, int tidx, int l, int r) {
	if (l == r) return t[tidx] = a[l];
	auto const m = (l + r) / 2;
	auto const x = init(t, a, tidx * 2, l, m);
	auto const y = init(t, a, tidx * 2 + 1, m + 1, r);
	return t[tidx] = x * y;
}
int update(int* t, int* a, int tidx, int x, int y, int l, int r) {
	if (x < l || x > r) return t[tidx];
	if (l == r) return t[tidx] = a[l] = y;
	auto const m = (l + r) / 2;
	auto const c = update(t, a, tidx * 2, x, y, l, m);
	auto const d = update(t, a, tidx * 2 + 1, x, y, m + 1, r);
	return t[tidx] = c * d;
}
int mul(int* t, int* a, int tidx, int start, int end, int l, int r) {
	if (r < start || l > end) return 1;
	if (start <= l && r <= end) return t[tidx];
	auto const m = (l + r) / 2;
	auto const x = mul(t, a, tidx * 2, start, end, l, m);
	auto const y = mul(t, a, tidx * 2 + 1, start, end, m + 1, r);
	return x * y;
}
int main() {
	int n, k;
	while (scanf("%d%d", &n, &k) != EOF) {
		auto a = new int[n + 1];
		auto t = new int[n * 4]();
		for (int i = 1; i <= n; i++) {
			scanf("%d", a + i);
			a[i] = (a[i] == 0 ? 0 : (a[i] > 0 ? 1 : -1));
		}
		init(t, a, 1, 1, n);
		while (k--) {
			char c[2];
			int x, y;
			scanf("%s%d%d", c, &x, &y);
			if (c[0] == 'C') {
				if (x == 4 && y == -5) {
					printf("");
				}
				y = (y == 0 ? 0 : (y > 0 ? 1 : -1));
				update(t, a, 1, x, y, 1, n);
			}
			else { // P
				int res = mul(t, a, 1, x, y, 1, n);
				if (res == 0) printf("0");
				else if (res > 0) printf("+");
				else printf("-");
			}
		}
		printf("\n");
		delete[] t;
		delete[] a;
	}
}