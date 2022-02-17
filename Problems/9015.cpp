#pragma GCC optimize("O3")
#include <algorithm>
#include <cstdlib>
#include <iostream>
using namespace std;
using ll = long long;
struct Point { ll x, y; };
bool comp(Point const &p1, Point const &p2) {
	return p1.x < p2.x || (p1.x == p2.x && p1.y < p2.y);
}
inline ll d2(Point const &p1, Point const &p2) {
	return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}
inline Point clockwise(Point const &p1, Point const &p2) {
	return { p2.x + p2.y - p1.y, p1.x - p2.x + p2.y };
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	ll t; cin >> t;
	while(t--) {
		ll n; cin >> n;
		auto p = (Point*)malloc(sizeof(Point) * n);
		for(int i = 0; i < n; i++) {
			cin >> p[i].x >> p[i].y;
		}
		sort(p, p + n, comp);
		ll max = 0;
		for(int i = 1; i < n; i++) {
			for(int j = 0; j < i; j++) {
				ll const dist = d2(p[i], p[j]);
				if(max >= dist) continue;
				auto const cw = clockwise(p[i], p[j]);
				if(binary_search(p, p + n, cw, comp)) {
					auto const cw2 = clockwise(p[j], cw);
					if(binary_search(p, p + n, cw2, comp)) {
						if(max < dist) max = dist;
						continue;
					}
				}
			}
		}
		cout << max << '\n';
		free(p);
	}
}