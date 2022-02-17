#include <iostream>
using namespace std;
using ll = long long;
ll power(ll a, ll p, ll mod) {
	if (!p) return 1;
	if (p == 1) return a;
	auto const r = power(a, p >> 1, mod);
	return (((r * r) % mod) * power(a, p & 1, mod)) % mod;
}
bool prime(int p) {
	for (int i = 2; i * i <= p; i++) {
		if (p % i) continue;
		return false;
	}
	return true;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	ll p, a;
	while (true) {
		cin >> p >> a;
		if (!p && !a) return 0;
		if (prime(p)) {
			printf("no\n");
			continue;
		}
		if (power(a, p, p) == a) {
			printf("yes\n");
		}
		else printf("no\n");
	}
}