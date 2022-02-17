#include <stdio.h>
int main() {
	int a, res = 0;
	for (int i = 0; i < 4; i++) {
		scanf("%d", &a);
		res += a;
	}
	printf("%d\n%d", res / 60, res % 60);
}