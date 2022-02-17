#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;
ll init(ll *t, ll const *a, int tidx, int l, int r) {
	if (l == r) return t[tidx] = a[l];
	auto const m = (l + r) / 2;
	auto const x = init(t, a, tidx * 2, l, m);
	auto const y = init(t, a, tidx * 2 + 1, m + 1, r);
	return t[tidx] = (x > y ? x : y);
}
ll max(ll* t, ll const* a, int tidx, int start, int end, int l, int r) {
	if (r < start || end < l) return -1;
	if (start <= l && r <= end) return t[tidx];
	auto const m = (l + r) / 2;
	auto const x = max(t, a, tidx * 2, start, end, l, m);
	auto const y = max(t, a, tidx * 2 + 1, start, end, m + 1, r);
	return x > y ? x : y;
}
int main() {
	ll n, k;
	cin >> n >> k;
	auto a = new ll[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);/*
	cout << "a:\n";
	for (int i = 0; i < n; i++) {
		cout << a[i] << ' ';
	} cout << '\n';*/
	auto arr = new ll[n + 1]();
	ll l = 0, r = 0;
	while (l < n) {
		arr[l + 1] = r - l;
		if (l == r) {
			r++;
			continue;
		}
		if (r == n) {
			l++;
			continue;
		}
		if (a[r] - a[l] <= k) {
			r++;
			continue;
		}
		l++;
	}
	auto t = new ll[n * 4]();
	init(t, arr, 1, 1, n);
	ll Max = 0;/*
	cout << "arr:\n";
	for (int i = 1; i <= n; i++) {
		cout << arr[i] << ' ';
	} cout << '\n';*/
	for (int i = 1; i <= n; i++) {
		ll sum = arr[i];
		if (i + arr[i] <= n) sum += max(t, arr, 1, i + arr[i], n, 1, n);
		if (Max < sum) Max = sum;
	}
	printf("%lld", Max);
	delete[] arr;
	delete[] a;
}