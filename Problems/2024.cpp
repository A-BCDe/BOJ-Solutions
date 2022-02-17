#include <stdio.h>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;
int main() {
	int m;
	scanf("%d", &m);
	vector<pair<int, int>> v;
	while(true) {
		int l, r;
		scanf("%d%d", &l, &r);
		if (l == 0 && r == 0) {
			break;
		}
		v.emplace_back(l, r);
	}
	sort(v.begin(), v.end());
	int cnt = 0;
	int piv = 0;
	int idx = 0;
	while (piv < m) {
		int x = piv;
		while (idx < v.size() && v[idx].first <= piv) {
			if (v[idx].second > x) x = v[idx].second;
			idx++;
		}
		if (x == piv) {
			printf("0");
			return 0;
		}
		piv = x;
		cnt++;
	}
	printf("%d", cnt);
}