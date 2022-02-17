#include <algorithm>
#include <iostream>
using namespace std;
using ll = long long;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	ll n;
	cin >> n;
	auto a = new ll[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	ll res = 3000000009;
	ll res1 = res, res2 = res, res3 = res;
	for (int i = 1; i < n - 1; i++) {
		for (int j = 0; j < i; j++) {
			auto const sum = a[i] + a[j];
			auto p = lower_bound(a + i + 1, a + n, -sum);
			if (p == a + n) {
				if (p != a + i + 1) {
					if (res > abs(*(p - 1) + sum)) {
						res = abs(*(p - 1) + sum);
						res1 = a[j];
						res2 = a[i];
						res3 = *(p - 1);
					}
				}
				continue;
			}
			if (res > abs(*p + sum)) {
				res = abs(*p + sum);
				res1 = a[j];
				res2 = a[i];
				res3 = *p;
			}
			if (p != a + i + 1) {
				if (res > abs(*(p - 1) + sum)) {
					res = abs(*(p - 1) + sum);
					res1 = a[j];
					res2 = a[i];
					res3 = *(p - 1);
				}
			}
		}
	}
	cout << res1 << ' ' << res2 << ' ' << res3;
}