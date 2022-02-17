#include <stdio.h>
#include <algorithm>
#include <utility>
using namespace std;
using point = pair<int, int>;
using line = pair<point, point>;
int ccw(point const& a, point const& b, point const& c) {
	int res = a.first * b.second + b.first * c.second + c.first * a.second;
	res -= a.second * b.first + b.second * c.first + c.second * a.first;
	if (res == 0) return 0;
	if (res > 0) return 1;
	return -1;
}
bool intersect(line const& x, line const& y) {
	point const& a = x.first;
	point const& b = x.second;
	point const& c = y.first;
	point const& d = y.second;
	auto const ab = ccw(a, b, c) * ccw(a, b, d);
	auto const cd = ccw(c, d, a) * ccw(c, d, b);
	if (ab == 0 && cd == 0) {
		return min(c, d) <= max(a, b) && min(a, b) <= max(c, d);
	}
	return ab <= 0 && cd <= 0;
}
struct uf {
	int* root, * rank;
	uf(int n) : root(new int[n]), rank(new int[n]) {
		for (int i = 0; i < n; i++) {
			root[i] = i;
			rank[i] = 1;
		}
	}
	int find(int x) {
		if (root[x] == x) return x;
		return root[x] = find(root[x]);
	}
	void merge(int a, int b) {
		auto x = find(a);
		auto y = find(b);
		if (x == y) return;
		if (rank[x] > rank[y]) swap(x, y);
		root[x] = y;
		if (rank[x] == rank[y]) rank[x]++;
	}
	bool check(int a, int b) { return find(a) == find(b); }
};
int main() {
	int n;
	scanf("%d", &n);
	auto a = new line[n];
	uf u(n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d%d", &a[i].first.first, &a[i].first.second, &a[i].second.first, &a[i].second.second);
		for (int j = 0; j < i; j++) {
			if (intersect(a[i], a[j])) {
				u.merge(i, j);
			}
		}
	}
	auto arr = new int[n]();
	int max = 0;
	int maxi = -1;
	for (int i = 0; i < n; i++) {
		if (max < ++arr[u.find(i)]) {
			max = arr[u.find(i)];
			maxi = u.find(i);
		}
	}
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i]) cnt++;
	}
	printf("%d\n%d", cnt, arr[maxi]);
}