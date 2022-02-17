#include <stdio.h>
int main() {
	int a[5];
	int res = 0;
	for (int i = 0; i < 5; i++) {
		scanf("%d", &a[i]);
		res += a[i] * a[i];
	}
	printf("%d", res % 10);
}