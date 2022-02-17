#include <numeric>
#include <stdio.h>
using ll = long long;
/// 
/// 5 6
///   1  2  3  4@ 5  6
///   7  8  9@10 11 12
///  13 14@15 16 17 18
///  19@20 21 22 23 24
/// @25 26 27 28 29@30
/// 
int main() {
	ll d, p, q;
	scanf("%lld%lld%lld", &d, &p, &q);
	auto l = std::lcm(p, q) / q;
	ll ans = -1;
	if (p > q) std::swap(p, q);
	for (ll i = 0; i < l; i++) {
		auto const x = q * i;
		if (x > d) {
			if (ans > x) ans = x;
			break;
		}
		if ((d - x) % p == 0) {
			printf("%lld", d);
			return 0;
		}
		if (ans < 0 || ans > x + ((d - x) / p + 1) * p) ans = x + ((d - x) / p + 1) * p;
	}
	printf("%lld", ans);
}