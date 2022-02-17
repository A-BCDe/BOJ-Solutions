#include <cmath>
#include <cstdio>
using ld = long double;
using ll = long long;
ld dfs(ld const* a, int* order, int n, int cnt) {
	if (cnt != n) {
		ld min = 16000000000;
		for (int i = 0; i < n; i++) {
			if (order[i]) continue;
			order[i] = cnt + 1;
			ld val = dfs(a, order, n, cnt + 1);
			if (min > val) min = val;
			order[i] = 0;
		}
		return min;
	}
	auto arr = new ld[n];
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < n; j++) {
			if (order[j] == i) {
				arr[i - 1] = a[j];
				break;
			}
		}
	}
	ld res = 0;
	for (int i = 0; i < (1 << (n - 1)); i++) {
		ld val = 0;
		int min = 0, max = 1;
		for (int j = 0; j < n - 1; j++) {
			if (i & (1 << j)) {
				val += sqrtl(arr[min] * arr[max]);
				min = max;
			}
			max++;
		}
		val += sqrtl(arr[min] * arr[max]);
		if (res < val) res = val;
	}
	delete[] arr;
	return res * 2;
}
int main() {
	int n;
	scanf("%d", &n);
	auto a = new ld[n];
	auto order = new int[n]();
	for (int i = 0; i < n; i++) scanf("%Lf", &a[i]);
	printf("%.12Lf", dfs(a, order, n, 0));
}