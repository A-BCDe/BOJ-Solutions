#include <stdio.h>
int main() {
	int tt;
	scanf("%d", &tt);
	while (tt--) {
		int n;
		scanf("%d", &n);
		if (n < 4 || n == 6) printf("0\n");
		else if (n == 4) printf("2\n");
		else printf("1\n");
	}
}