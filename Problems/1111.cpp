#include <stdio.h>
#include <cmath>
int main() {
	int n;
	scanf("%d", &n);
	auto a = new int[n];
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	if (n >= 2 && a[1] == a[0]) {
		for (int i = 2; i < n; i++) {
			if (a[i] != a[0]) {
				printf("B");
				return 0;
			}
		}
		printf("%d", a[0]);
		return 0;
	}
	if (n <= 2) {
		printf("A");
		return 0;
	}
	if (abs(a[2] - a[1]) % abs(a[1] - a[0]) != 0) {
		printf("B");
		return 0;
	}
	int x = (a[2] - a[1]) / (a[1] - a[0]);
	int y = a[1] - a[0] * x;
	for (int i = 1; i + 2 < n; i++) {
		if (a[i + 2] != a[i + 1] * x + y) {
			printf("B");
			return 0;
		}
	}
	printf("%d", a[n - 1] * x + y);
}