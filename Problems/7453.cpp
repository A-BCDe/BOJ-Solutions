#include <stdio.h>
#include <algorithm>
using ll = long long;
int main() {
	ll n;
	scanf("%lld", &n);
	ll* a[4];
	for (int i = 0; i < 4; i++) {
		a[i] = new ll[n];
	}
	for (int i = 0; i < n; i++) {
		scanf("%lld%lld%lld%lld", &a[0][i], &a[1][i], &a[2][i], &a[3][i]);
	}
	ll* b = new ll[n * n];
	ll* c = new ll[n * n];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			b[i * n + j] = a[0][i] + a[1][j];
			c[i * n + j] = a[2][i] + a[3][j];
		}
	}
	std::sort(c, c + n * n);
	ll cnt = 0;
	for (int i = 0; i < n * n; i++) {
		auto p = std::lower_bound(c, c + n * n, -b[i]);
		auto q = std::upper_bound(c, c + n * n, -b[i]);
		if (p == c + n * n || *p != -b[i]) continue;
		cnt += q - p;
	}
	printf("%lld", cnt);
	delete[] b;
	delete[] c;
}