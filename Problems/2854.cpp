#include <stdio.h>
using ll = long long;
constexpr ll p = 1000000007;
int main() {
	int n;
	scanf("%d", &n);
	auto a = new ll[n + 1];
	auto b = new ll[n] ;
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	for (int i = 1; i < n; i++) {
		scanf("%lld", &b[i]);
	}
	ll* d[3];
	d[0] = new ll[n + 1]();
	d[1] = new ll[n + 1]();
	d[2] = new ll[n + 1]();
	d[0][1] = a[1];
	d[1][1] = 0; // i <- i - 1
	d[2][1] = b[1]; // i <- i
	for (int i = 2; i <= n; i++) {
		d[0][i] = ((d[0][i - 1] * a[i]) % p + (d[1][i - 1] * a[i]) % p + (d[2][i - 1] * a[i]) % p) % p;
		d[1][i] = ((d[0][i - 1] * b[i - 1]) % p + (d[1][i - 1] * b[i - 1]) % p + (d[2][i - 1] * (b[i - 1] - 1)) % p) % p;
		if (i < n) {
			d[2][i] = ((d[0][i - 1] * b[i]) % p + (d[1][i - 1] * b[i]) % p + (d[2][i - 1] * b[i]) % p) % p;
		}
	}
	printf("%lld", (d[0][n] + d[1][n] + d[2][n]) % p);
}