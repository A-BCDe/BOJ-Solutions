#include <stdio.h>
int main() {
	int x, y;
	while(true) {
		scanf("%d%d", &x, &y);
		if(!x && !y) return 0;
		printf("%d\n", x + y);
	}
}