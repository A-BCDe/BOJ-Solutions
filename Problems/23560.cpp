#include <stdio.h>
using ll = long long;
ll dp(ll arr[46][3][3], int remain, int l, int r) {
	if (arr[remain][l][r] != -1) return arr[remain][l][r];
	if (remain == 1) return arr[remain][l][r] = 1;
	ll res = 0;
	if (remain % 3 != 2) {
		if (l) res = dp(arr, remain - 1, l - 1, r);
		if (r) res += dp(arr, remain - 1, l, r - 1);
	}
	else {
		if (!l) res = dp(arr, remain - 1, 2, r);
		if (!r) res += dp(arr, remain - 1, l, 2);
	}
	return arr[remain][l][r] = res;
}
int main() {
	int n; scanf("%d", &n);
	ll arr[46][3][3];
	for (int i = 0; i < 46; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) arr[i][j][k] = -1;
		}
	}
	printf("%lld", dp(arr, 3 * n, 1, 1));
}