#include <queue>
#include <stdio.h>
using ll = long long;
int main() {
	int tt;
	scanf("%d", &tt);
	while (tt--) {
		int m;
		scanf("%d", &m);
		printf("%d\n", (m + 1) / 2);
		std::priority_queue<ll> left, right;
		ll n, cnt = 1;
		scanf("%lld", &n);
		printf("%lld ", n);
		left.push(n);
		for (int i = 1; i < m; i++) {
			ll x;
			scanf("%lld", &x);
			if (!left.empty() && x < left.top()) {
				left.push(x);
				x = left.top();
				left.pop();
			}
			if (!right.empty() && -x < right.top()) {
				right.push(-x);
				x = -right.top();
				right.pop();
			}
			if (left.size() == right.size()) {
				printf("%lld ", x);
				if (cnt == 9 && i != m - 1) {
					printf("\n");
				}
				cnt = (cnt + 1) % 10;
				left.push(x);
			}
			else right.push(-x);
		}
		printf("\n");
	}
}