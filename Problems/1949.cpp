#include <iostream>
#include <utility>
#include <vector>
using namespace std;
inline int max(pair<int, int> const& p) { return p.first > p.second ? p.first : p.second; }
pair<int, int> dp(vector<int> const* v, int const* a, int now, int prev) {
	int off = 0, on = a[now];
	for (auto next : v[now]) {
		if (next == prev) continue;
		auto const p = dp(v, a, next, now);
		off += max(p);
		on += p.first;
	}
	return { off, on };
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n; cin >> n;
	auto a = new int[n + 1];
	for (int i = 1; i <= n; i++) cin >> a[i];
	auto v = new vector<int>[n + 1];
	for (int i = 1; i < n; i++) {
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	auto const p = dp(v, a, 1, 0);
	cout << max(p);
	delete[] v;
	delete[] a;
}