#include <cmath>
#include <cstdio>
using ld = long double;
int main() {
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	ld l = -1000000, r = 1000000;
	while (l + 1e-12 < r) {
		auto const m = (l + r) / 2;
		auto const x = a * m + b * sin(m) - c;
		if (x > 0) r = m;
		else if (x < 0) l = m;
		else break;
	}
	printf("%.15Lf", (l + r) / 2);
}