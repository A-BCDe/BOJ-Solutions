#include <stdio.h>
#include <utility>
using namespace std;
int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	// N / M
	n %= m;
	if (n == 0) {
		printf("0");
		return 0;
	}
	int g = gcd(n, m);
	int res = m - g;
	printf("%d", res);
}