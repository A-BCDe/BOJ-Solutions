#include <stdio.h>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;
int sqrt(int x) {
	if (x < 2) return x;
	int l = 0, r = x;
	int res = 0;
	while (l < r) {
		long long const m = (l + r) / 2;
		if (m * m == x) {
			return (int)m;
		}
		if (m * m > x) {
			r = m;
			continue;
		}
		res = m;
		l = m + 1;
	}
	return res;
}
int dist(pair<int, int> const& a, pair<int, int> const& b) {
	return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}
int f(pair<int, int>* a, int n, int l, int r) {
	if (l + 1 >= r) return 800000001;
	auto const m = (l + r) / 2;
	auto const x = f(a, n, l, m);
	auto const y = f(a, n, m, r);
	int d = (x < y ? x : y);
	auto lo = lower_bound(a + l, a + r, make_pair(a[m].first - sqrt(d), -10001));
	auto hi = upper_bound(a + l, a + r, make_pair(a[m].first + sqrt(d), 10001));
	vector<pair<int, int>> v;
	v.reserve(hi - lo);
	for (auto it = lo; it != hi; ++it) {
		v.emplace_back(*it);
	}
	sort(v.begin(), v.end(), [](pair<int, int> const& a, pair<int, int> const& b) {
		return a.second < b.second || (a.second == b.second && a.first < b.first);
	});
	for (int i = 0; i < v.size() - 1; i++) {
		for (int j = i + 1; j < v.size(); j++) {
			if ((v[j].second - v[i].second) * (v[j].second - v[i].second) >= d) break;
			auto const D = dist(v[i], v[j]);
			if (D < d) d = D;
		}
	}
	return d;
}
int main() {
	int n;
	scanf("%d", &n);
	auto a = new pair<int, int>[n];
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &a[i].first, &a[i].second);
	}
	sort(a, a + n);
	printf("%d", f(a, n, 0, n)); // [l, r)
	delete[] a;
}