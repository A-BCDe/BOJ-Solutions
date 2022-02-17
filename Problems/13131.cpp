#include <stdio.h>
int main() {
	// 1: 38
	// 2: 30
	// 3: 2
	long long n;
	scanf("%lld", &n);
	printf("%lld", n * 38 + n * n * 30 + n * n * n * 2);
}