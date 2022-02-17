#include <stdio.h>
int main() {
	long long r, c, n;
	scanf("%lld%lld%lld", &r, &c, &n);
	printf("%lld", ((r - 1) / n + 1) * ((c - 1) / n + 1));
}