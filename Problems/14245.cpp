#include <stdio.h>
#include <utility>
using namespace std;
int init(pair<int, int>* t, int const* a, int tidx, int l, int r) {
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
int update(pair<int, int>* t, int* a, int tidx, int start, int end, int val, int l, int r) {
	if (r < start || end < l) return t[tidx].first ^ (((r - l + 1) % 2) ? t[tidx].second : 0);
	if (l == r) {
		t[tidx].first ^= val ^ t[tidx].second;
		t[tidx].second = 0;
		return t[tidx].first;
	}
	if (start <= l && r <= end) {
		t[tidx].second ^= val;
		return t[tidx].first ^ (((r - l + 1) % 2) ? t[tidx].second : 0);
	}
	auto const m = (l + r) / 2;
	if (t[tidx].second) {
		update(t, a, tidx * 2, l, r, t[tidx].second, l, m);
		update(t, a, tidx * 2 + 1, l, r, t[tidx].second, m + 1, r);
		t[tidx].second = 0;
	}
	auto const x = update(t, a, tidx * 2, start, end, val, l, m);
	auto const y = update(t, a, tidx * 2 + 1, start, end, val, m + 1, r);
	t[tidx].first = x ^ y;
	return t[tidx].first;
}
int find(pair<int, int>* t, int* a, int tidx, int idx, int l, int r) {
	if (idx < l || idx > r) return 0;
	if (l == r) {
		return t[tidx].first ^ t[tidx].second;
	}
	auto const m = (l + r) / 2;
	auto const x = find(t, a, tidx * 2, idx, l, m);
	auto const y = find(t, a, tidx * 2 + 1, idx, m + 1, r);
	return x ^ y ^ t[tidx].second;
}
int main() {
	int n;
	scanf("%d", &n);
	auto a = new int[n + 1];
	auto t = new pair<int, int>[n * 4]();
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
			int i;
			scanf("%d", &i);
			printf("%d\n", find(t, a, 1, i + 1, 1, n));
		}
	}
	delete[] a;
	delete[] t;
}