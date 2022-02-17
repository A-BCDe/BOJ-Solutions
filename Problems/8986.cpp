#include <stdio.h>
using ll = long long;
ll abs(ll a) { return a > 0 ? a : -a; }
ll f(ll const* a, int n, ll d) {
	ll dist = 0;
	ll res = 0;
	for (int i = 0; i < n; i++) {
		res += abs(a[i] - dist);
		dist += d;
	}
	return res;
}
int main() {
	int n;
	scanf("%d", &n);
	auto a = new ll[n];
	for (int i = 0; i < n; i++) {
		scanf("%lld", &a[i]);
	}
	ll l = 0, r = 1000000000;
	while (l < r) {
		auto const m1 = (l * 2 + r) / 3;
		auto const m2 = (l + r * 2) / 3;
		if (m1 == l || m2 == r) break;
		auto const res1 = f(a, n, m1);
		auto const res2 = f(a, n, m2);
		if (res1 < res2) r = m2;
		else l = m1;
	}
	ll min = f(a, n, r);
	for (ll i = l; i < r; i++) {
		auto const res = f(a, n, i);
		if (min > res) {
			min = res;
		}
	}
	printf("%lld", min);
	delete[] a;
}