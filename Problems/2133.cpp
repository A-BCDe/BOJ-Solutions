#include <algorithm>
#include <cstdio>
using ll = long long;
ll f(ll **dp, ll n, ll cur, ll state) {
	ll &val = dp[cur][state];
	if(val != -1) return val;
	if(cur == n - 1) return val = (state >> 2);
	if(cur == n - 2) return val = ((state & 6) == 0 || (state & 6) == 6);
	if(cur == n - 3) return val = (state == 1 || state == 4 || state == 7);
	if(state & 4) return val = f(dp, n, cur + 1, (state << 1) & 7);
	val = f(dp, n, cur + 1, ((state << 1) & 7) | 1); // 2 * 1
	if(cur % 3 != 2 && !(state & 2)) {
		val += f(dp, n, cur + 2, (state << 2) & 7); // 1 * 2
	}
	return val;
}
int main() {
	ll n;
	scanf("%lld", &n);
	auto dp = new ll*[n * 3];
	for(int i = 0; i < n * 3; i++) {
		dp[i] = new ll[8];
		std::fill(dp[i], dp[i] + 8, -1);
	}
	printf("%lld", f(dp, n * 3, 0, 0));
}