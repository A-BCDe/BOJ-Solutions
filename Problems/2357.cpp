#include <stdio.h>
#include <utility>
using namespace std;
void init(pair<int, int>* t, int const* a, int tidx, int l, int r) {
	if (l == r) {
		t[tidx] = { a[l], a[l] };
		return;
	}
	auto const m = (l + r) / 2;
	init(t, a, tidx * 2, l, m);
	init(t, a, tidx * 2 + 1, m + 1, r);
	auto const x = t[tidx * 2].first < t[tidx * 2 + 1].first ? t[tidx * 2].first : t[tidx * 2 + 1].first;
	auto const y = t[tidx * 2].second > t[tidx * 2 + 1].second ? t[tidx * 2].second : t[tidx * 2 + 1].second;
	t[tidx] = { x, y };
}
pair<int, int> minmax(pair<int, int> const* t, int tidx, int start, int end, int l, int r) {
	if (end < l || r < start) return { 1000000001, 0 };
	if (start <= l && r <= end) return t[tidx];
	auto const m = (l + r) / 2;
	auto const x = minmax(t, tidx * 2, start, end, l, m);
	auto const y = minmax(t, tidx * 2 + 1, start, end, m + 1, r);
	return { (x.first < y.first ? x.first : y.first), (x.second > y.second ? x.second : y.second) };
}
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	auto a = new int[n + 1];
	auto t = new pair<int, int>[n * 4];
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	init(t, a, 1, 1, n);
	delete[] a;
	while (m--) {
		int x, y;
		scanf("%d%d", &x, &y);
		auto const p = minmax(t, 1, x, y, 1, n);
		printf("%d %d\n", p.first, p.second);
	}
}