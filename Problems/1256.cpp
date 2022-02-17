#include <cstdio>
#include <algorithm>
using ll = long long;
void f(ll **C, ll n, ll m, ll k) {
	if(!n && !m) return;
	if(!n || C[n + m - 1][n - 1] < k) {
		printf("z");
		f(C, n, m - 1, k - C[n + m - 1][n - 1]);
	}
	else {
		printf("a");
		f(C, n - 1, m, k);
	}
}
int main() {
	ll n, m, k;
	scanf("%lld%lld%lld", &n, &m, &k);
	auto C = new ll*[n + m + 1];
	for(ll i = 0; i <= n + m; i++) {
		C[i] = new ll[i + 1]();
		C[i][0] = 1;
		for(ll j = 1; j < i; j++) {
			C[i][j] = std::min(k << 1, C[i - 1][j - 1] + C[i - 1][j]);
		} C[i][i] = 1;
	}
	if(C[n + m][n] < k) {
		printf("-1");
		return 0;
	}
	f(C, n, m, k);
}