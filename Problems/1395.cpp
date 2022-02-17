#include <stdio.h>
#include <utility>
using namespace std;
inline int calc(pair<int, int> const& p, int n) {
	if (p.second) return n - p.first;
	return p.first;
}
int update(pair<int, int>* t, int tidx, int start, int end, int l, int r) {
	if (end < l || r < start) return calc(t[tidx], r - l + 1);
	if (start <= l && r <= end) {
		t[tidx].second = 1 - t[tidx].second;
		return calc(t[tidx], r - l + 1);
	}
	auto const m = (l + r) / 2;
	if (t[tidx].second) {
		t[tidx * 2].second = 1 - t[tidx * 2].second;
		t[tidx * 2 + 1].second = 1 - t[tidx * 2 + 1].second;
		t[tidx].first = calc(t[tidx], r - l + 1);
		t[tidx].second = 0;
	}
	auto const x = update(t, tidx * 2, start, end, l, m);
	auto const y = update(t, tidx * 2 + 1, start, end, m + 1, r);
	return t[tidx].first = x + y;
}
int on(pair<int, int>* t, int tidx, int start, int end, int l, int r) {
	if (end < l || r < start) return 0;
	if (start <= l && r <= end) return calc(t[tidx], r - l + 1);
	auto const m = (l + r) / 2;
	if (t[tidx].second) {
		t[tidx * 2].second = 1 - t[tidx * 2].second;
		t[tidx * 2 + 1].second = 1 - t[tidx * 2 + 1].second;
		t[tidx].first = calc(t[tidx], r - l + 1);
		t[tidx].second = 0;
	}
	auto const x = on(t, tidx * 2, start, end, l, m);
	auto const y = on(t, tidx * 2 + 1, start, end, m + 1, r);
	return x + y;
}
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	auto t = new pair<int, int>[n * 4]();
	while (m--) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		if (!x) {
			update(t, 1, y, z, 1, n);
		}
		else {
			printf("%d\n", on(t, 1, y, z, 1, n));
		}
	}
}