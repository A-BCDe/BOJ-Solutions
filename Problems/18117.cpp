#include <stdio.h>
#include <vector>
using namespace std;
using ull = unsigned long long;
ull gcd(ull a, ull b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}
ull mul(ull a, ull b, ull m) {
	ull res = 0;
	for (int i = 0; i < 64; i++) {
		ull x = ((b >> i) & 1);
		res = (res + (a % m) * x) % m;
		a = (a << 1) % m;
	}

	return res;
}
ull power(ull n, ull a, ull m) { // (n^a) % m
	if (a == 0) return 1;
	if (a == 1) return n % m;
	ull r = power(n, a >> 1, m);
	return mul(mul(r, r, m), power(n, a & 1, m), m);
}
int main() {
	int tt;
	scanf("%d", &tt);
	while (tt--) {
		ull a, b, i, n;
		scanf("%lld%lld%lld%lld", &a, &b, &i, &n);
		ull g = gcd(a, b);
		a /= g; b /= g;
		auto x = power(10, i - 1, b);
		a = mul(a, x, b);
		a -= (a / b) * b;
		a *= 10;
		for (int j = 0; j < n; j++) {
			printf("%lld", a / b);
			a -= (a / b) * b;
			a *= 10;
		}
		printf("\n");
	}
}