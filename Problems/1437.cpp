#include <stdio.h>
int pow(int a, int n) {
	if (n == 0)return 1;
	if (n == 1)return a;
	auto const x = pow(a, n / 2);

	return (((x * x) % 10007) * pow(a, n % 2)) % 10007;
}
int main() {
	int n;
	scanf("%d", &n);
	if (n < 5) {
		printf("%d", n);
		return 0;
	}
	if (n % 3 == 0) {
		printf("%d", pow(3, n / 3));
		return 0;
	}
	if (n % 3 == 1) {
		printf("%d", (4 * pow(3, (n - 4) / 3) % 10007));
		return 0;
	}
	if (n % 3 == 2) {
		printf("%d", (2 * pow(3, (n - 2) / 3)) % 10007);
		return 0;
	}
}