#include <cmath>
#include <cstdio>
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		if (n == 1) {
			printf("1\n");
			continue;
		}
		long double res = 0;
		for (int i = 1; i <= n; i++) {
			res += log10l(i);
		}
		printf("%.0Lf\n", ceill(res));
	}
}