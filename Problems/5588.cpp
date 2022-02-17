#include <stdio.h>
#include <algorithm>
#include <utility>
using namespace std;
int main() {
	int m;
	scanf("%d", &m);
	pair<int, int> init;
	pair<int, int> ta, tb;
	auto a = new pair<int, int>[m - 1];
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &tb.first, &tb.second);
		if (i) {
			a[i - 1].first = tb.first - ta.first;
			a[i - 1].second = tb.second - ta.second;
		}
		else init = tb;
		ta = tb;
	}
	int n;
	scanf("%d", &n);
	auto b = new pair<int, int>[n];
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &b[i].first, &b[i].second);
	}
	sort(b, b + n);
	for (int i = 0; i < n; i++) {
		int cur = i;
		int j = 0;
		for (; j < m - 1; j++) {
			auto const prev = cur;
			cur = lower_bound(b, b + n, make_pair(b[prev].first + a[j].first, b[prev].second + a[j].second)) - b;
			if (cur == n || b[cur] != make_pair(b[prev].first + a[j].first, b[prev].second + a[j].second)) {
				break;
			}
		}
		if (j == m - 1) {
			printf("%d %d", b[i].first - init.first, b[i].second - init.second);
			return 0;
		}
	}
	delete[] a;
}