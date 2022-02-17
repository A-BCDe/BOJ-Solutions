#include <stdio.h>
int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	int res = 0;
	for (int i = 0; i < n; i++) {
		int x; scanf("%d", &x);
		res ^= (x & 1);
	}
	if (res) printf("John");
	else printf("Preston");
}