#include <algorithm>
#include <stdio.h>
#include <map>
#include <set>
using namespace std;
using ll = long long;
constexpr ll M = 1000000007;
ll f(map<pair<int, int>, ll>& m, set<int> s, int mx) {
	auto const x = min(*s.rbegin(), mx);
	if (s.size() == 1) return x;
	if (m.find({ s.size(), x }) != m.end()) return m[{ now, x }];
}
int main() {
	int tt;
	scanf("%d", &tt);
	map<pair<int, int>, ll> m;
	while (tt--) {
		int n;
		scanf("%d", &n);
		set<int> s;
		for (int i = 0; i < n; i++) {
			int x;
			scanf("%d", &x);
			s.insert(x);
		}
		printf("%lld\n", f(m, s, *s.rbegin()));
	}
}