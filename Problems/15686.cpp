#include <stdio.h>
#include <vector>
using namespace std;
int ff(int x) { return x > 0 ? x : -x; }
int f(vector<pair<int, int>>& chicken, vector<pair<int, int>>& house, pair<int, int>* v, int m, int idx, int cnt) {
	if (m == cnt) {
		int sum = 0;
		for (int i = 0; i < house.size(); i++) {
			int min = 1000000000;
			for (int j = 0; j < m; j++) {
				int x = ff(v[j].first - house[i].first) + ff(v[j].second - house[i].second);
				if (min > x) min = x;
			}
			sum += min;
		}
		return sum;
	}
	int min = 1000000000;
	for (int i = idx; i <= chicken.size() - m + cnt; i++) {
		v[cnt] = chicken[i];
		int x = f(chicken, house, v, m, i + 1, cnt + 1);
		if (min > x) min = x;
	}
	return min;
}
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	auto a = new int* [n];
	vector<pair<int, int>> house, chicken;
	for (int i = 0; i < n; i++) {
		a[i] = new int[n];
		for (int j = 0; j < n; j++) {
			scanf("%d", &a[i][j]);
			if (a[i][j] == 1) {
				house.emplace_back(i, j);
			}
			else if (a[i][j] == 2) {
				chicken.emplace_back(i, j);
			}
		}
	}
	auto v = new pair<int, int>[m]();
	printf("%d", f(chicken, house, v, m, 0, 0));
	delete[] v;
	for (int i = 0; i < n; i++) {
		delete[] a[i];
	}
	delete[] a;
}