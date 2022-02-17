#include <stdio.h>
using ll = long long;
constexpr ll M = 10007;
ll power(ll a, ll n) {
	if(!n) return 1;
	if(n == 1) return a;
	ll r = power(a, n >> 1);
	return (((r * r) % M) * power(a, n & 1)) % M;
}
ll inv(ll a) { return power(a, M - 2); }
int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	ll res = 1;
	for(int i = n - k + 1; i <= n; i++) res = (res * i) % M;
	for(int i = 1; i <= k; i++) res = (res * inv(i)) % M;
	printf("%lld", res);
}