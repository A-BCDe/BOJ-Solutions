#include <iostream>
using namespace std;
using ll = long long;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	ll n;
	cin >> n;
	ll res = 1;
	ll arr[30]{};
	for (int i = 0; i < n; i++) {
		ll x;
		cin >> x;
		int idx = 0;
		while (x) {
			arr[idx++] += (x & 1);
			x >>= 1;
		}
	}
	ll x;
	for (int i = 0; i < n; i++) {
		x = 0;
		int idx = 0;
		for (int i = 0; i < 30; i++) {
			x |= ((arr[i] != 0) << i);
			arr[i] -= (arr[i] != 0);
		}
		res = (res * x) % 1000000007;
	}
	cout << res;
}