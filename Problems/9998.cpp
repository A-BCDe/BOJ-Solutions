#include <stdio.h>
using ll = long long;
ll abs(ll x) { return x > 0 ? x : -x; }
int main() {
	int n;
	scanf("%d", &n);
	auto a = new ll[n];
	auto b = new ll[n];
	for (int i = 0; i < n; i++) {
		scanf("%lld", &a[i]);
	}
	for (int i = 0; i < n; i++) {
		scanf("%lld", &b[i]);
	}
	ll l = 0, r = 1000000000000;
	ll min = 300000000000000000;
	while (l < r) {
		ll const m = (l + r) / 2;
		ll res = 0;
		ll arr[2][3] = {};
		for (int i = 0; i < n; i++) {
			ll const h = m + abs(i - n / 2);
			if (a[i] == h) arr[0][1]++;
			else if (a[i] > h) arr[0][2]++;
			else arr[0][0]++;
			if (b[i] == h) arr[1][1]++;
			else if (b[i] > h) arr[1][2]++;
			else arr[1][0]++;
		}
		if (res == 0) {
			
		}
	}
	delete[] b;
	delete[] a;
}