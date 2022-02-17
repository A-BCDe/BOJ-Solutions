#include <iostream>
#include <string>
using namespace std;
using ll = long long;
ll gcd(ll a, ll b) {
	if (!b) return a;
	return gcd(b, a % b);
}
ll power(ll n) {
	if (!n) return 1;
	if (n == 1) return 10;
	ll const r = power(n >> 1);
	return r * r * power(n & 1);
}
int main() {
	int t;
	string s;
	cin >> t;
	while (t--) {
		cin >> s;
		bool flag = false;
		ll nonrepeat = 0, repeat = 0;
		ll cnt = 0;
		for (int i = 2; i < s.size(); i++) {
			if (s[i] == ')') break;
			if (s[i] == '(') {
				flag = true;
				continue;
			}
			nonrepeat = nonrepeat * 10 + (s[i] - '0');
			if (flag) {
				repeat = repeat * 10 + (s[i] - '0');
				cnt++;
			}
		}
		if (!flag) {
			ll x = s.size() - 2;
			ll g = gcd(power(x), nonrepeat);
			cout << nonrepeat / g << '/' << power(x) / g << '\n';
			continue;
		}
		ll den = (power(cnt) - 1) * power(s.size() - 4 - cnt);
		ll g = gcd(den, nonrepeat - nonrepeat / power(cnt));
		cout << (nonrepeat - nonrepeat / power(cnt)) / g << '/' << den / g << '\n';
	}
}