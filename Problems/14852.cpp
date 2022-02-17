#include <cstdio>
#include <algorithm>
using ll = long long;
constexpr ll M = 1000000007;
ll f(ll **dp, ll n, ll cur, ll state) {
	if(dp[cur][state] != -1) return dp[cur][state];
	if(cur == n - 1) return dp[cur][state] = dp[cur][state | 2] = 1;
	if(cur == n - 2) {
		ll &val = (dp[cur][state] = f(dp, n, cur + 1, ((state << 1) & 3) | 1));
		if(state & 2) return val;
		if(!(cur & 1) && !(state & 1)) {
			val = (val + 1) % M;
		}
		return val;
	}
	ll &val = (dp[cur][state] = f(dp, n, cur + 1, (state << 1) & 3));
	if(state & 2) return val;
	val = (val + f(dp, n, cur + 1, ((state << 1) & 3) | 1)) % M; // 2 * 1
	if(!(cur & 1) && !(state & 1)) {
		val = (val + f(dp, n, cur + 2, 0)) % M; // 1 * 2
	}
	return val;
}
int main() {
	ll n;
	scanf("%lld", &n);
	auto dp = new ll*[n << 1];
	for(ll i = 0; i < (n << 1); i++) {
		dp[i] = new ll[4];
		std::fill(dp[i], dp[i] + 4, -1);
	}
	printf("%lld", f(dp, n << 1, 0, 0));
}