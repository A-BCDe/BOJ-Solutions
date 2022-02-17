#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
// 00 01 02 03 04 05 06 07 08 09 -> 1 * (0 + 1 + ... + 9)
// 00 01 02 ... 97 98 99 -> 20 * (0 + 1 + ... + 9)
// 000 ~ 999 -> 300 * 45
// nÀÚ¸® -> n * 10^(n - 1) * 45
ll power(int n) {
	if (!n) return 1;
	if (n == 1) return 10;
	auto const r = power(n / 2);
	return r * r * power(n & 1);
}
ll zerotosum(int n) { // 0 ~ 10^n - 1
	return n * power(n - 1) * 45;
}
// 123000 ~ 123999
// zerotosum(3) + sumdigit(123) * power(3)
ll sumdigit(ll x) {
	ll res = 0;
	while (x) {
		res += x % 10;
		x /= 10;
	}
	return res;
}
ll sum(ll val, int i) {
	auto const k = power(i);
	return zerotosum(i) + sumdigit(val / k) * k;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int tt;
	cin >> tt;
	while (tt--) {
		ll a, b;
		cin >> a >> b;
		ll res = zerotosum(15);
		//cout << "res = " << res << '\n';
		if (b == 1000000000000000) res++, b--;
		ll l = 0, r = 1000000000000000;
		for (int i = 14; i; i--) {
			auto const k = power(i);
			while (l + k <= a) {
				//cout << "l: i = " << i << ", sum = " << sum(l, i) << '\n';
				res -= sum(l, i);
				l += k;
			}
			while (r - k > b) {
				//cout << "r: i = " << i << ", sum = " << sum(r - k, i) << '\n';
				res -= sum(r - k, i);
				r -= k;
			}
			//printf("l = %lld, r = %lld, res = %lld\n", l, r, res);
		}
		while (l < a) {
			res -= sumdigit(l++);
		}
		while (r - 1 > b) {
			res -= sumdigit(--r);
		}
		cout << res << '\n';
	}
}