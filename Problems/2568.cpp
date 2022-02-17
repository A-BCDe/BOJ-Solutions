#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	auto p = new pair<int, int>[n];
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &p[i].first, &p[i].second);
	}
	vector<int> v;
	sort(p, p + n);
	auto a = new int[n];
	for (int i = 0; i < n; i++) {
		if (v.empty() || v.back() < p[i].second) {
			a[i] = v.size();
			v.push_back(p[i].second);
			continue;
		}
		auto d = lower_bound(v.begin(), v.end(), p[i].second) - v.begin();
		v[d] = p[i].second;
		a[i] = d;
	}
	auto cnt = v.size() - 1;
	cout << n - v.size() << '\n';
	vector<int> vv;
	vv.reserve(v.size());
	for (int i = n - 1; i >= 0; i--) {
		if (a[i] == cnt) {
			cnt--;
			continue;
		}
		vv.emplace_back(p[i].first);
	}
	for (int i = vv.size() - 1; i >= 0; i--) {
		printf("%d\n", vv[i]);
	}

	delete[] a;
	delete[] p;
}