#include <stdio.h>
using ll = long long;
int main() {
	ll a, b;
	scanf("%lld%lld", &a, &b);
	auto arr = new bool[b - a + 1]();
	for (ll i = 2; i * i <= b; i++) {
		auto const I = i * i;
		for (ll j = (b / I) * I; j >= a; j -= I) {
			arr[j - a] = true;
		}
	}
	int cnt = 0;
	for (ll i = 0; i <= b - a; i++) {
		if (!arr[i]) cnt++;
	}
	printf("%d", cnt);
}