#include <cstdio>
int main() {
	int a1, a0, c1, c2, n;
	scanf("%d%d%d%d%d", &a1, &a0, &c1, &c2, &n);
	int d = a1 - c1;
	bool ans = true;
	if(d < 0 || (d == 0 && a0 < 0)) ans = false;
	else if(d * n + a0 < 0) ans = false;
	else {
		d = a1 - c2;
		if(d > 0 || (d == 0 && a0 > 0)) ans = false;
		else if(d * n + a0 > 0) ans = false;
	} printf("%d", ans);
}