#include <cstdio>
using ll = long long;
int main() {
	ll n;
	scanf("%lld", &n);
	auto D = new ll[n + 1];
	D[0] = 0, D[1] = 0, D[2] = 1;
	for(ll i = 3; i <= n; i++) {
		D[i] = ((i - 1) * (D[i - 1] + D[i - 2])) % 1000000000;
	}
	printf("%lld", D[n]);
}