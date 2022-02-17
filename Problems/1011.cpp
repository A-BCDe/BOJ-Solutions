#include <stdio.h>
using ll = long long;
ll square(ll n) {
	ll l = 0, r = n;
	ll res = n;
	while (l < r) {
		auto const m = (l + r) / 2;
		if (m * m == n) return m;
		if (m * m > n) {
			res = m;
			r = m;
		}
		else l = m + 1;
	}
	return res;
}
ll nsquare(ll n) {
	ll l = 0, r = n;
	ll res = n;
	while (l < r) {
		auto const m = (l + r) / 2;
		if (m * (m + 1) == n) return m;
		if (m * (m + 1) > n) {
			res = m;
			r = m;
		}
		else l = m + 1;
	}
	return res;
}
ll nsqf(ll n) {
	return n << 1;
}
ll sqf(ll n) {
	return (n << 1) - 1;
}
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		ll a, b, n;
		scanf("%lld%lld", &a, &b);
		n = b - a;
		ll sq = square(n);
		ll nsq = nsquare(n);
		//printf("sq = %lld, nsq = %lld\n", sq, nsq);
		if (nsq < sq) {
			printf("%lld\n", nsqf(nsq));
		}
		else printf("%lld\n", sqf(sq));
	}
}