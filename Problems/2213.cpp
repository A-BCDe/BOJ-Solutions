#include <algorithm>
#include <stdio.h>
#include <utility>
#include <vector>
using namespace std;
inline int max(pair<int, int> const& p) { return p.first < p.second ? p.second : p.first; }
pair<int, int> dp(vector<pair<int, int>>* v, int const* a, int now, int prev) {
	int off = 0;
	int on = a[now];
	for (auto& next : v[now]) {
		if (next.first == prev) continue;
		auto const p = dp(v, a, next.first, now);
		if (p.first > p.second) {
			off += p.first;
			next.second = 1;
		}
		else off += p.second;
		on += p.first;
	}
	return { off, on };
}
void save(vector<pair<int, int>> const* v, vector<int>& res, int now, int prev, int on) {
	if (on) {
		res.push_back(now);
		for (auto const& next : v[now]) {
			if (next.first == prev) continue;
			save(v, res, next.first, now, 0);
		}
	}
	else {
		for (auto const& next : v[now]) {
			if (next.first == prev) continue;
			save(v, res, next.first, now, 1 - next.second);
		}
	}
}
int main() {
	int n;
	scanf("%d", &n);
	auto a = new int[n + 1];
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	auto v = new vector<pair<int, int>>[n + 1];
	for (int i = 1; i < n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		v[x].emplace_back(y, 0);
		v[y].emplace_back(x, 0);
	}
	auto const p = dp(v, a, 1, 0);
	printf("%d\n", max(p));
	vector<int> res;
	save(v, res, 1, 0, p.first <= p.second);
	sort(res.begin(), res.end());
	for (auto now : res) printf("%d ", now);
	delete[] a;
	delete[] v;
}