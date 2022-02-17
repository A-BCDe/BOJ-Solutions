#include <stdio.h>
#include <utility>
using namespace std;
using pii = pair<int, int>; // value, lazy xor value
int init(pii* t, int const* a, int tidx, int l, int r) {
	if (l == r) {
		t[tidx] = make_pair(a[l], 0);
		return a[l];
	}
	auto const m = (l + r) / 2;
	auto const x = init(t, a, tidx * 2, l, m);
	auto const y = init(t, a, tidx * 2 + 1, m + 1, r);
	t[tidx] = make_pair(x ^ y, 0);
	return t[tidx].first;
}
int update(pii* t, int* a, int tidx, int start, int end, int val, int l, int r) {
	if (end < l || r < start) {
		return t[tidx].first ^ (((r - l + 1) % 2) ? t[tidx].second : 0);
	}
	if (l == r) {
		t[tidx].first ^= t[tidx].second ^ val;
		t[tidx].second = 0;
		return t[tidx].first;
	}
	if (start <= l && r <= end) {
		t[tidx].second ^= val;
		return t[tidx].first ^ (((r - l + 1) % 2) ? t[tidx].second : 0);
	}
	auto const m = (l + r) / 2;
	update(t, a, tidx * 2, l, r, t[tidx].second, l, m);
	update(t, a, tidx * 2 + 1, l, r, t[tidx].second, m + 1, r);
	t[tidx].second = 0;
	auto const x = update(t, a, tidx * 2, start, end, val, l, m);
	auto const y = update(t, a, tidx * 2 + 1, start, end, val, m + 1, r);
	return t[tidx].first = x ^ y;
}
int fxor(pii* t, int* a, int tidx, int start, int end, int l, int r) {
	if (end < l || r < start) return 0;
	if (start <= l && r <= end) {
		return t[tidx].first ^ (((r - l + 1) % 2) ? t[tidx].second : 0);
	}
	auto const m = (l + r) / 2;
	t[tidx * 2].second ^= t[tidx].second;
	t[tidx * 2 + 1].second ^= t[tidx].second;
	t[tidx].first ^= (((r - l + 1) % 2) ? t[tidx].second : 0);
	t[tidx].second = 0;
	auto const x = fxor(t, a, tidx * 2, start, end, l, m);
	auto const y = fxor(t, a, tidx * 2 + 1, start, end, m + 1, r);
	return x ^ y;
}
int main() {
	int n;
	scanf("%d", &n);
	auto a = new int[n + 1];
	auto t = new pii[n * 4];
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
			int i, j, k;
			scanf("%d%d%d", &i, &j, &k);
			update(t, a, 1, i + 1, j + 1, k, 1, n);
		}
		else {
			int i, j;
			scanf("%d%d", &i, &j);
			printf("%d\n", fxor(t, a, 1, i + 1, j + 1, 1, n));
		}
	}
	delete[] a;
	delete[] t;
}