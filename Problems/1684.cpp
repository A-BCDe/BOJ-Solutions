#include <stdio.h>
int abs(int x) { return x > 0 ? x : -x; }
int gcd(int a, int b) {
	if (!b) return a;
	return gcd(b, a % b);
}
int main() {
	int n;
	scanf("%d", &n);
	auto a = new int[n];
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	int g = abs(a[1] - a[0]);
	for (int i = 2; i < n; i++) {
		g = gcd(g, abs(a[i] - a[i - 1]));
	}
	printf("%d", g);
}