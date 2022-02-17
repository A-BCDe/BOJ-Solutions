#include <stdio.h>
int main() {
	int x=0;
	for (int i = 0; i < 2; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		x += a * b;
	}
	printf("%d", x);
}