#include <stdio.h>
int abs(int x) {
	if (x > 0) return x;
	return -x;
}
int gcd(int a, int b) {
	if (b == 0) return abs(a);
	return gcd(abs(b), abs(a) % abs(b));
}
int main() {
	int tt;
	scanf("%d", &tt);
	while (tt--) {
		int n;
		scanf("%d", &n);
		auto a = new int[n];
		bool flag = true;
		int g;
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
			if (i && a[i] != a[i - 1]) flag = false;
		}
		if (flag) {
			printf("INFINITY\n");
			goto END;
		}
		g = abs(a[1] - a[0]);
		for (int i = 2; i < n; i++) {
			g = gcd(g, a[i] - a[i - 1]);
		}
		printf("%d\n", g);
	END:delete[] a;
	}
}