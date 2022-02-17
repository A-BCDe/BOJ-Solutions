#include <stdio.h>
#include <cassert>
#include <limits>
#include <utility>
using namespace std;
using ll = long long;
ll init(ll* t, pair<ll, ll> const* a, int tidx, int l, int r) {
	if (l == r) return t[tidx] = a[l].second;
	auto const m = (l + r) / 2;
	auto const x = init(t, a, tidx * 2, l, m);
	auto const y = init(t, a, tidx * 2 + 1, m + 1, r);
	return t[tidx] = (x > y ? x : y);
}
ll max(ll const* t, int tidx, int start, int end, int l, int r) {
	if (end < l || r < start) return 0;
	if (start <= l && r <= end) return t[tidx];
	auto const m = (l + r) / 2;
	auto const x = max(t, tidx * 2, start, end, l, m);
	auto const y = max(t, tidx * 2 + 1, start, end, m + 1, r);
	return x > y ? x : y;
}
int main() {
	int n;
	ll m;
	scanf("%d%lld", &n, &m);
	auto a = new pair<ll, ll>[n + 1];
	auto t = new ll[n * 4]();
	for (int i = 1; i <= n; i++) {
		scanf("%lld%lld", &a[i].first, &a[i].second);
		if (i) {
			a[i].first += a[i - 1].first;
		}
	}
	init(t, a, 1, 1, n);
	ll min = numeric_limits<ll>::max();
	for (int i = 1; i <= n; i++) {
		int l = i, r = n + 1;
		int res = r;
		while (l < r) {
			int const mid = (l + r) / 2;
			ll F = a[mid].first;
			if (i > 1) F -= a[i - 1].first;
			if (F >= m) {
				res = mid;
				r = mid;
			}
			else l = mid + 1;
		}
		if (res == n + 1) continue;
		ll F = a[res].first;
		if (i > 1) F -= a[i - 1].first;
		if (F >= m) {
			ll const S = max(t, 1, i, res, 1, n);
			if (min > S) min = S;
		}
	}
	printf("%lld", min);
	delete[] a;
	delete[] t;
}