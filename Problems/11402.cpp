#include <stdio.h>
using ll = long long;
int main() {
	ll n, k, m;
	scanf("%lld%lld%lld", &n, &k, &m);
	auto a = new ll* [m + 1];
	for (int i = 0; i <= m; i++) {
		a[i] = new ll[i + 2](); // nCk = n-1Ck-1 + n-1Ck, 1C0 = 1 = 0C0
		a[i][0] = 1;
		for (int j = 1; j <= i; j++) {
			a[i][j] = (a[i - 1][j] + a[i - 1][j - 1]) % m;
		}
	}
	ll res = 1;
	while (n) {
		res = (res * a[n % m][k % m]) % m;
		n /= m;
		k /= m;
	}
	printf("%lld", res);
	for (int i = 0; i <= m; i++) {
		delete[] a[i];
	}
	delete[] a;
}