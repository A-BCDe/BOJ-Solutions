#include <stdio.h>
int main() {
	int n;
	scanf("%d", &n);
	int sum = 0, k = 5;
	while (k <= n) {
		sum += n / k;
		k *= 5;
	}
	printf("%d", sum);
}