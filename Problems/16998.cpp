#include <iostream>
#include <numeric>
using namespace std;
using ll = long long;
ll f(ll p, ll q, ll n) {
	if (!p) return 0;
	if (p >= q) return (p / q) * (n * (n + 1) / 2) + f(p % q, q, n);
	return n * ((p * n) / q) + n / q - f(q, p, (p * n) / q);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t; cin >> t;
	while (t--) {
		ll p, q, n;
		cin >> p >> q >> n;
		ll g = gcd(p, q);
		p /= g; q /= g;
		cout << g * (p * (n * (n + 1) / 2) - q * f(p, q, n)) << '\n';
	}
}