#include <numeric>
#include <stdio.h>
int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	int g = 360;
	while(n--) {
		int x;
		scanf("%d", &x);
		g = std::gcd(g, x);
	}
	while (k--) {
		int x;
		scanf("%d", &x);
		printf(x % g ? "NO\n" : "YES\n");
	}
}