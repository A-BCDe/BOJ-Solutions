#include <stdio.h>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	auto a = new bool* [n];
	auto v = new pair<int, vector<int>>[n];
	for (int i = 0; i < n; i++) {
		a[i] = new bool[m];
		v[i].first = 1;
		char c[100];
		scanf("%s", c);
		for (int j = 0; j < m; j++) {
			a[i][j] = (c[j] == '1');
			if (a[i][j] == false) {
				v[i].second.push_back(j);
			}
		}
		for (int j = 0; j < i; j++) {
			auto flag = true;
			for (int k = 0; k < m; k++) {
				if (a[i][k] != a[j][k]) { flag = false; break; }
			}
			if (flag) { v[i].first++; v[j].first++; }
		}
	}
	sort(v, v + n);
	int k;
	scanf("%d", &k);
	if (k > m) {
		if (((k - m) & 1) == 0) k = m;
		else k = m - 1;
	}
	for (int i = n - 1; i >= 0; i--) {
		if (v[i].second.size() > k) continue;
		if (((k - v[i].second.size()) & 1) == 1) continue;
		printf("%d", v[i].first);
		return 0;
	}
	printf("0");
}