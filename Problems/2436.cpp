#include <stdio.h>
int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}
int main() {
	int x, y;
	scanf("%d%d", &x, &y);
	int a = y / x;
	int res = 1;
	for (int i = 2; i * i <= a; i++) {
		if (a % i == 0 && gcd(a / i, i) == 1) res = i;
	}
	printf("%d %d", x * res, y / res);
}