#include <stdio.h>
using ll = long long;
ll dp(ll const *a, ll **arr, ll const *sum, int l, int r) {
	if(arr[l][r]) return arr[l][r];
	if(l == r) return 0;
	ll min = 10000000000000;
	auto const xx = sum[r + 1] - sum[l];
	for(int i = l; i < r; i++) {
		auto const x = dp(a, arr, sum, l, i) + dp(a, arr, sum, i + 1, r) + xx;
		if(min > x) min = x;
	}
	return arr[l][r] = min;
}
int main() {
	int tt;
	scanf("%d", &tt);
	while(tt--) {
		int n;
		scanf("%d", &n);
		auto a = new ll[n];
		auto sum = new ll[n + 1]();
		auto arr = new ll*[n];
		for(int i = 0; i < n; i++) {
			arr[i] = new ll[n]();
			scanf("%lld", &a[i]);
			sum[i + 1] = sum[i] + a[i];
		}
		printf("%lld\n", dp(a, arr, sum, 0, n - 1));
		for(int i = 0; i < n; i++) delete[] arr[i];
		delete[] arr;
		delete[] sum;
		delete[] a;
	}
}