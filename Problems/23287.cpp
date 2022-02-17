#include <iostream>
#include <numeric>
using namespace std;
using ll = long long;
struct str { ll a, b, c, d; };
inline str op(str const& x, str const& y) {
	return {
		x.a * y.a + x.b * y.b + x.c * y.c + x.d * y.d,
		abs(x.a * y.b - x.b * y.a - x.c * y.d + x.d * y.c),
		abs(x.a * y.c + x.b * y.d - x.c * y.a - x.d * y.b),
		abs(x.a * y.d - x.b * y.c + x.c * y.b - x.d * y.a)
	};
}
str make(ll n) {
	for (ll a = 0; a * a <= n; a++) {
		for (ll b = 0; b <= a && a * a + b * b <= n; b++) {
			for (ll c = 0; c <= b && a * a + b * b + c * c <= n; c++) {
				for (ll d = 0; d <= c && a * a + b * b + c * c + d * d <= n; d++) {
					if (a * a + b * b + c * c + d * d == n) return { a, b, c, d };
				}
			}
		}
	}
}
int main() {
	ll n;
	cin >> n;
	str res = { 1, 0, 0, 0 };
	for (ll i = 2; i <= 100000; i++) {
		int cnt = 0;
		while (n % i == 0) {
			cnt++;
			n /= i;
		}
		if (!cnt) continue;
		str const c = make(i);
		while (cnt--) res = op(res, c);
	}
	if (n > 1) res = op(res, make(n));
	cout << res.a << ' ' << res.b << ' ' << res.c << ' ' << res.d;
}