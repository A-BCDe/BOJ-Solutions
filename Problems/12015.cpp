#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	auto a = new int[n];
	vector<int> v;
	for (int i = 0; i < n; i++) {
		scanf("%d", a + i);
		if (v.empty() || v.back() < a[i]) {
			v.push_back(a[i]);
			continue;
		}
		auto d = lower_bound(v.begin(), v.end(), a[i]) - v.begin();
		v[d] = a[i];
	}
	printf("%d", (int)v.size());
	delete[] a;
}