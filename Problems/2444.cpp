#include <stdio.h>
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			printf(" ");
		}
		for (int j = 0; j < 2 * i + 1; j++) {
			printf("*");
		}
		printf("\n");
	}
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < i + 1; j++) {
			printf(" ");
		}
		// 0     -> 2n - 3 = 2n - 3 - 2 * 0
		// 1     -> 2n - 5 = 2n - 3 - 2 * 1
		// n - 2 -> 1	   = 2n - 3 - 2 * (n - 2)
		for (int j = 0; j < 2 * n - 3 - 2 * i; j++) {
			printf("*");
		}
		printf("\n");
	}
}