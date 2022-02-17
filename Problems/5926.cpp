#include <stdio.h>
#include <algorithm>
#include <set>
#include <map>
#include <utility>
using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	auto a = new pair<int, int>[n];
	set<int> s;
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &a[i].first, &a[i].second);
		if (s.find(a[i].second) == s.end()) s.insert(a[i].second);
	}
	sort(a, a + n);
	int l = 0, r = 0; // l <= i < r, { a[i].second }.size == s.size ?
	map<int, int> m;
	int min = 1000000000;
	while (l < n) {
		if (l == r) {
			if (r < n) m[a[r++].second]++;
			else --m[a[l++].second];
			continue;
		}
		if (m.size() == s.size()) {
			if (min > a[r - 1].first - a[l].first) min = a[r - 1].first - a[l].first;
			if (--m[a[l++].second] == 0) {
				m.erase(a[l - 1].second);
			}
			continue;
		}
		if (r == n) {
			if (--m[a[l++].second] == 0) {
				m.erase(a[l - 1].second);
			}
			continue;
		}
		++m[a[r++].second];
	}
	printf("%d", min);
}