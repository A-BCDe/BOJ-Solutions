#include <stdio.h>
int main() {
	int a, res = 0;
	for (int i = 0; i < 5; i++) {
		scanf("%d", &a);
		res += a;
	}
	printf("%d", res);
}