#include <stdio.h>
using ll = long long;
int main() {
	ll a[31][31] = {};
	for (int i = 0; i < 31; i++) {
		a[i][0] = a[i][i] = 1;
		for (int j = 1; j < i; j++) {
			a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
		}
	}
	int tt;
	scanf("%d", &tt);
	while (tt--) {
		int n, m;
		scanf("%d%d", &n, &m);
		printf("%lld\n", a[m][n]);
	}
}