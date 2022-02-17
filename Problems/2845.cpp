#include <stdio.h>
int main() {
	int a, b;
	scanf("%d%d", &a, &b);
	for (int i = 0; i < 5; i++) {
		int x;
		scanf("%d", &x);
		printf("%d ", x - a * b);
	}
}