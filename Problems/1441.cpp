#include <stdio.h>
using ll = long long;
ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}
ll lcm(ll a, ll b) {
	return a / gcd(a, b) * b;
}
ll f(ll const* a, bool* visited, ll n, ll l, ll r, int cnt, int idx) {
	if (idx == n) {
		if (!cnt) return 0;
		ll mul = 1;
		for (int i = 0; i < n; i++) {
			if (!visited[i]) continue;
			mul = lcm(mul, a[i]);
			if (mul > r) return 0;
		}
		return (r / mul - (l - 1) / mul) * (((cnt & 1) * 2) - 1);
	}
	visited[idx] = true;
	ll res = f(a, visited, n, l, r, cnt + 1, idx + 1);
	visited[idx] = false;
	res += f(a, visited, n, l, r, cnt, idx + 1);
	return res;
}
int main() {
	ll n, l, r;
	scanf("%lld%lld%lld", &n, &l, &r);
	auto a = new ll[n];
	for (ll i = 0; i < n; i++) {
		scanf("%lld", &a[i]);
		if (a[i] == 1) {
			printf("%lld", r - l + 1);
			return 0;
		}
	}
	auto visited = new bool[n]();
	ll res = f(a, visited, n, l, r, 0, 0);
	printf("%lld", res);
}