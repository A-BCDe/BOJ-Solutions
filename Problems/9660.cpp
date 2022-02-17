#include <stdio.h>
int main() {
	long long n;
	scanf("%lld", &n);
	// 0101111 0101111
	switch (n % 7) {
	case 0:
	case 2:
		printf("CY");
		break;
	default:
		printf("SK");
	}
}