#include <algorithm>
#include <iostream>
#include <utility>
using namespace std;
using ll = long long;
using point = pair<ll, ll>;
using segment = pair<point, point>;
ll ccw(point const& a, point const& b, point const& c) {
	ll res = a.first * b.second + b.first * c.second + c.first * a.second;
	res -= a.second * b.first + b.second * c.first + c.second * a.first;
	if (!res) return 0;
	if (res > 0) return 1;
	return -1;
}
bool intersect(segment const& x, segment const& y) {
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
	segment x, y;
	cin >> x.first.first >> x.first.second >> x.second.first >> x.second.second;
	cin >> y.first.first >> y.first.second >> y.second.first >> y.second.second;
	cout << intersect(x, y);
}