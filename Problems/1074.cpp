#include <stdio.h>
int po(int n) {
	if (n < 2) return n + 1;
	auto r = po(n / 2);
	return r * r * po(n % 2);
}
int f(int n, int r, int c) {
	if (n == 0) return 0;
	auto const p = po(n);
	if (r < p / 2) {
		if (c < p / 2) {
			return f(n - 1, r, c);
		}
		return (p / 2) * (p / 2) + f(n - 1, r, c - p / 2);
	}
	if (c < p / 2) {
		return (p / 2) * p + f(n - 1, r - p / 2, c);
	}
	return 3 * (p / 2) * (p / 2) + f(n - 1, r - p / 2, c - p / 2);
}
int main() {
	int n, r, c;
	scanf("%d%d%d", &n, &r, &c);
	printf("%d", f(n, r, c));
}