#include <cstdio>
int main() {
	int a1, a0, c, n;
	scanf("%d%d%d%d", &a1, &a0, &c, &n);
	a1 -= c;
	if(a1 < 0 || (a1 == 0 && a0 < 0)) printf("0");
	else if(a1 * n + a0 < 0) printf("0");
	else printf("1");
}