#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	auto a = new int[n];
	auto p = new int[n];
	vector<int> v;
	for (int i = 0; i < n; i++) {
		scanf("%d", a + i);
		if (v.empty() || v.back() < a[i]) {
			p[i] = v.size();
			v.push_back(a[i]);
			continue;
		}
		v[p[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin()] = a[i];
	}
	vector<int> vv(v.size());
	auto cnt = v.size() - 1;
	for (int i = n - 1; i >= 0; i--) {
		if (p[i] == cnt) {
			vv[cnt--] = a[i];
		}
	}
	printf("%d\n", (int)vv.size());
	for (auto now : vv) {
		printf("%d ", now);
	}
}