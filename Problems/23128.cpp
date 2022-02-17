#include <algorithm>
#include <iostream>
using namespace std;
using ll = long long;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin >> n;
	auto a = new ll[1000001]();
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		a[x] = 1;
	}
	ll cnt = 0;
	for (ll i = 1; i < 500000; i++) {
		if (!a[i]) continue;
		ll val;
		for (ll m = 1; (val = m * (i * 2 + m)) <= 1000000; m++) {
			cnt += a[val];
		}
	}
	cout << cnt;
	delete[] a;
}