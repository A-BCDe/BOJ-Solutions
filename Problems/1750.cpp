#include <stdio.h>
int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}
long long pow(int n) {
	if (n < 2) return n + 1;
	long long x = pow(n / 2);
	return (x * x * (n % 2 ? 2 : 1)) % 10000003;
}
long long f(int* a, int n, int g, int k) {
	long long res = 0;
	for (int i = k + 1; i < n; i++) {
		if (gcd(g, a[i]) == 1) {
			res = (res + pow(n - i - 1)) % 10000003;
		}
		else {
			res = (res + f(a, n, gcd(g, a[i]), i)) % 10000003;
		}
	}
	return res;
}
int main() {
	int n;
	scanf("%d", &n);
	auto a = new int[n];
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	long long res = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == 1) res = (res + pow(n - i - 1)) % 10000003;
		else res = (res + f(a, n ,a[i], i)) % 10000003;
	}
	printf("%lld", res);
	delete[] a;
}