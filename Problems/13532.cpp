#include <stdio.h>
#include <math.h>
int low(double x) {
	int r = x;
	while (r > x) r--;
	while (r + 1 < x) r++;
	return r;
}
int main() {
	int n;
	scanf("%d", &n);
	if (n % 2) {
		double x = log10(5) + log10(2) * n - 1;
		if (low(x) == x) printf("%d", low(x) - 1);
		else printf("%d", low(x));
	}
	else {
		double x = log10(2) * n;
		printf("%d", low(x));
	}
}