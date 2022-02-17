#include <stdio.h>
long long norm(long long n) {
	int x = 0;
	if (n < 0) {
		n = (1000000007 - (-n) % 1000000007);
	}
	n %= 1000000007;
	return n;
}
long long inv(long long n) { // n != 0
	if (n == 1) return 1;
	return norm(-(1000000007 / n) * inv(1000000007 % n));
}
int main() {
	auto a = new int* [5001];
	for (int i = 0; i < 5001; i++) {
		a[i] = new int[5001]();
		if (i == 0) continue;
		for (int j = 0; j < 5001; j++) {
			if (j == 0) {
				a[i][j] = 1; continue;
			}
			a[i][j] = (a[i][j - 1] + a[i - 1][j]) % 1000000007;
		}
	}
	int tt;
	scanf("%d", &tt);
	while (tt--) {
		long long n;
		scanf("%lld", &n);
		if (n & 1) {
			printf("0\n");
			continue;
		}
		n /= 2;
		long long x = inv(n + 1);
		printf("%lld\n", (x * a[n * 2][n]) % 1000000007);
	}
	for (int i = 0; i < 5001; i++) {
		delete[] a[i];
	}
	delete[] a;
}