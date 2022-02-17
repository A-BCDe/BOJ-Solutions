#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
using namespace std;
using ll = long long;
using point = pair<ll, ll>;
ll ccw(point const& a, point const& b, point const& c) {
	ll res = a.first * b.second + b.first * c.second + c.first * a.second;
	res -= a.second * b.first + b.second + c.first + c.second * a.first;
	if (!res) return 0;
	if (res > 0) return 1;
	return -1;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin >> n;
	auto p = new point[n];
	int cnt = 0;
	int mini = 0;
	for (int i = 0; i < n; i++) {
		ll x, y;
		string c;
		cin >> x >> y >> c;
		if (c[0] == 'Y') {
			p[cnt] = { x, y };
			if (p[mini].first > x || (p[mini].first == x && p[mini].second > y)) {
				mini = cnt;
			}
			cnt++;
		}
	}
	if (mini != 0) {
		swap(p[0], p[mini]);
	}
	auto const piv = p[0];
	sort(p + 1, p + cnt, [&piv](point const& a, point const& b) {
		return ccw(b, piv, a) >= 0;
	});
	cout << cnt << '\n';
	for (int i = 0; i < cnt; i++) {
		cout << p[i].first << ' ' << p[i].second << '\n';
	}
}