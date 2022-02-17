#include <algorithm>
#include <stdio.h>
#include <map>
#include <utility>
#include <vector>
using ll = long long;
using namespace std;
int main() {
	int n;
	while (true) {
		scanf("%d", &n);
		if (!n) return 0;
		auto a = new ll[n];
		for (int i = 0; i < n; i++) {
			scanf("%lld", &a[i]);
		}
		sort(a, a + n);
		map<ll, vector<pair<ll, ll>>> sum, sub;
		for (int i = 1; i < n; i++) {
			for (int j = 0; j < i; j++) {
				sum[a[i] + a[j]].emplace_back(i, j);
				sub[a[i] - a[j]].emplace_back(i, j);
				if(a[j] != a[i]) sub[a[j] - a[i]].emplace_back(i, j);
			}
		}
		for (auto const& now : sum) {
			
		}
		delete[] a;
	}
}