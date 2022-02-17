#include <iostream>
#include <math.h>
#include <utility>
using namespace std;
long long dist(pair<int, int> const& p) { return (long long)p.first * p.first + (long long)p.second * p.second; }
pair<int, int> dfs(pair<int, int>* a, bool* b, int const n, int cur, int cnt) {
	if (cur == n) {
		if (cnt == n / 2) {
			int x = 0, y = 0;
			for (int i = 0; i < n; i++) {
				if (b[i]) { x += a[i].first; y += a[i].second; }
				else { x -= a[i].first; y -= a[i].second; }
			}
			return make_pair(x, y);
		}
		else return make_pair(1000000, 1000000);
	}
	b[cur] = false;
	auto p1 = dfs(a, b, n, cur + 1, cnt);
	b[cur] = true;
	auto p2 = dfs(a, b, n, cur + 1, cnt + 1);
	if (dist(p1) > dist(p2)) return p2;
	else return p1;
}
int main() {
	int tt;
	scanf("%d", &tt);
	while (tt--) {
		int n;
		scanf("%d", &n);
		auto a = new pair<int, int>[n];
		auto b = new bool[n]();
		for (int i = 0; i < n; i++) {
			scanf("%d%d", &a[i].first, &a[i].second);
		}
		auto const res = dfs(a, b, n, 0, 0);
		auto const d = dist(res);
		cout << fixed;
		cout.precision(6);
		cout << sqrt(d) << endl;
		delete[] a;
		delete[] b;
	}
}