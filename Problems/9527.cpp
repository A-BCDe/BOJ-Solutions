#include <stdio.h>
using ll = long long;
int main() {
	ll a, b;
	scanf("%lld%lld", &a, &b);
	int const c = 56;
	ll l = 0, r = ((ll)1 << c) - 1;
	ll sum = ((ll)1 << (c - 1)) * c;
	int cur = c - 1;
	ll lc = 0, rc = 1;
	while ((l < a || b < r) && cur) {
		if (l < a && l + ((ll)1 << cur) <= a) {
			l += ((ll)1 << cur);
			sum -= ((ll)1 << (cur - 1)) * (cur + 2 * lc);
			// 100 101
			lc++;
		}
		if (b < r && r - ((ll)1 << cur) >= b) {
			r -= ((ll)1 << cur);
			sum -= ((ll)1 << (cur - 1)) * (cur + 2 * rc);
		}
		else rc++;
		cur--;
	}
	if (l < a) {
		l += 1;
		sum -= lc;
	}
	if (b < r) {
		r -= 1;
		sum -= rc;
	}
	printf("%lld", sum);
}