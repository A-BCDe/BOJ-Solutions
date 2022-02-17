#include <stdio.h>
#include <algorithm>
#include <utility>
using namespace std;
using ll = long long;
using point = pair<ll, ll>;
using line = pair<point, point>;
ll ccw(point const& a, point const& b, point const& c) {
	ll res = a.first * b.second + b.first * c.second + c.first * a.second;
	res -= a.second * b.first + b.second * c.first + c.second * a.first;
	if (res == 0) return 0;
	if (res > 0) return 1;
	return -1;
}
bool intersect(line const& x, line const& y) {
	auto const& a = x.first;
	auto const& b = x.second;
	auto const& c = y.first;
	auto const& d = y.second;
	auto const ab = ccw(a, b, c) * ccw(a, b, d);
	auto const cd = ccw(c, d, a) * ccw(c, d, b);
	if (ab == 0 && cd == 0) {
		return min(a, b) <= max(c, d) && min(c, d) <= max(a, b);
	}
	return ab <= 0 && cd <= 0;
}
int main() {
	int tt;
	scanf("%d", &tt);
	while (tt--) {
		line l;
		line l1, l2, l3, l4;
		scanf("%lld%lld%lld%lld", &l.first.first, &l.first.second, &l.second.first, &l.second.second);
		scanf("%lld%lld%lld%lld", &l1.first.first, &l1.first.second, &l2.second.first, &l2.second.second);
		l3.first = l1.first;
		l4.second = l2.second;
		l1.second = l2.first = { l1.first.first, l2.second.second };
		l3.second = l4.first = { l2.second.first, l1.first.second };
		if (intersect(l, l1) || intersect(l, l2) || intersect(l, l3) || intersect(l, l4)) {
			printf("T\n");
			continue;
		}
		if (l.first.first <= max(l1.first.first, l2.second.first) && l.first.first >= min(l1.first.first, l2.second.first) && l.first.second <= max(l1.first.second, l2.second.second) && l.first.second >= min(l1.first.second, l2.second.second)) {
			printf("T\n");
			continue;
		}
		printf("F\n");
	}
}