#include <stdio.h>
int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}
int main() {
	int n, m;
	scanf("%d", &n);
	auto a = new int[n];
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	scanf("%d", &m);
	long long res = 1;
	bool flag = false;
	for (int i = 0; i < m; i++) {
		int b;
		scanf("%d", &b);
		for (int j = 0; j < n && b > 1; j++) {
			int g = gcd(a[j], b);
			res *= g;
			if (res >= 1000000000) {
				flag = true;
				res %= 1000000000;
			}
			a[j] /= g; b /= g;
		}
	}
	if (!flag) printf("%lld", res);
	else printf("%09lld", res);
}