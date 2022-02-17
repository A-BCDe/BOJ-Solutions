#include <cstdio>
using ll = long long;
int main() {
	ll n;
	scanf("%lld", &n);
	ll l = 0, r = 0;
	ll sum = 0, cnt = 0;
	while(r <= n + 1) {
		if(l == r) {
			sum += r;
			r++;
			continue;
		}
		if(sum == n) {
			cnt++;
			sum += r;
			r++;
			continue;
		}
		if(sum < n) {
			sum += r;
			r++;
			continue;
		}
		sum -= l;
		l++;
	}
	printf("%lld", cnt);
}