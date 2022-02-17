#include <stdio.h>
int main() {
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	printf("%d %d\n%d %d\n%d %d\n%d %d", a - c, b - c, a - c, b + c, a + c, b + c, a + c, b - c);
}