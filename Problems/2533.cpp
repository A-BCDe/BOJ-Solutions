#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;
inline int mn(pair<int, int> const& p) { return p.first > p.second ? p.second : p.first; }
pair<int, int> dp(vector<int> const* v, int parent, int root) {
	int colored = 1, not_colored = 0;
	for (auto const& now : v[root]) {
		if (now == parent) continue;
		auto const p = dp(v, root, now);
		not_colored += p.first;
		colored += mn(p);
	}
	return make_pair(colored, not_colored);
}
int main() {
	int n;
	scanf("%d", &n);
	auto v = new vector<int>[n + 1];
	for (int i = 1; i < n; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	printf("%d", mn(dp(v, -1, 1)));
	delete[] v;
}