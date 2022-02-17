#include <stdio.h>
int main() {
	int x = 0;
	for (int i = 0; i < 6; i++) {
		int a;
		scanf("%d", &a);
		x += a;
	}
	printf("%d", x * 5);
}