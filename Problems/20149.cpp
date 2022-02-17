#include <algorithm>
#include <iostream>
#include <utility>
using ll = long long;
using point = std::pair<ll, ll>;
using line = std::pair<point, point>;
ll ccw(point const& x, point const& y, point const& z) {
	ll res = x.first * y.second + y.first * z.second + z.first * x.second;
	res -= x.second * y.first + y.second * z.first + z.second * x.first;
	if (res == 0) return 0;
	if (res > 0) return 1;
	return -1;
}
std::pair<bool, bool> intersect(line const& x, line const& y) {
	auto const& a = x.first;
	auto const& b = x.second;
	auto const& c = y.first;
	auto const& d = y.second;
	auto const ab = ccw(a, b, c) * ccw(a, b, d);
	auto const cd = ccw(c, d, a) * ccw(c, d, b);
	if (ab == 0 && cd == 0) {
		auto r1 = min(a, b);
		auto r2 = max(a, b);
		auto r3 = min(c, d);
		auto r4 = max(c, d);
		auto const res1 = min(a, b) <= max(c, d) && min(c, d) <= max(a, b);
		auto const res2 = (r1 == r2 || r3 == r4 || r1 == r4 || r2 == r3 || r1 == r3 || r2 == r4);
		return { res1, res2 };
	}
	return { ab <= 0 && cd <= 0, 1 };
}
point operator+(point const& a, point const& b) {
	return { a.first + b.first, a.second + b.second };
}
point operator-(point const& a, point const& b) {
	return { a.first - b.first, a.second - b.second };
}
int main() {
	std::cout.precision(9);
	line l1, l2;
	std::cin >> l1.first.first >> l1.first.second >> l1.second.first >> l1.second.second >> l2.first.first >> l2.first.second >> l2.second.first >> l2.second.second;
	auto res = intersect(l1, l2);
	std::cout << (res.first ? 1 : 0);
	if (!(res.first && res.second)) return 0;
	if (l1.first == l2.first) {
		std::cout << '\n' << l1.first.first << ' ' << l1.first.second;
		return 0;
	}
	if (l1.second == l2.first) {
		std::cout << '\n' << l1.second.first << ' ' << l1.second.second;
		return 0;
	}
	if (l1.first == l2.second) {
		std::cout << '\n' << l1.first.first << ' ' << l1.first.second;
		return 0;
	}
	if (l1.second == l2.second) {
		std::cout << '\n' << l1.second.first << ' ' << l1.second.second;
		return 0;
	}
	auto const& x1 = l1.first.first;
	auto const& x2 = l1.second.first;
	auto const& x3 = l2.first.first;
	auto const& x4 = l2.second.first;
	auto const& y1 = l1.first.second;
	auto const& y2 = l1.second.second;
	auto const& y3 = l2.first.second;
	auto const& y4 = l2.second.second;
	long double x_num = (x1 * y2 - y1 * x2) * (x3 - x4) - (x1 - x2) * (x3 * y4 - y3 * x4);
	long double x_den = (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4);
	long double y_num = (x1 * y2 - y1 * x2) * (y3 - y4) - (y1 - y2) * (x3 * y4 - y3 * x4);
	long double y_den = x_den;
	std::cout << '\n' << x_num / x_den << ' ' << y_num / y_den;
}