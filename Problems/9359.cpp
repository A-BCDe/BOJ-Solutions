#include <math.h>
#include <stdio.h>
#include <vector>
using ll = long long;
using namespace std;
int main() {
	int t; scanf("%d", &t);
	for(int tt = 1; tt <= t; tt++) {
		printf("Case #%d: ", tt);
		ll a, b, n, total;
		vector<ll> v;
		scanf("%lld%lld%lld", &a, &b, &n);
		total = b - a + 1;
		for (ll i = 2; i * i <= n; i++) {
			bool flag = false;
			while (n % i == 0) {
				n /= i;
				flag = true;
			}
			if (flag) {
				auto const len = v.size();
				for (int j = 0; j < len; j++) {
					v.push_back(-v[j] * i);
				} v.push_back(i);
			}
		}
		if (n != 1) {
			auto const len = v.size();
			for (int j = 0; j < len; j++) {
				v.push_back(-v[j] * n);
			} v.push_back(n);
		}
		for (ll now : v) {
			ll const val = abs(now);
			ll cnt = b / val - a / val;
			cnt += (a % val == 0);
			if (now > 0) total -= cnt;
			else total += cnt;
		}
		printf("%lld\n", total);
	}
}