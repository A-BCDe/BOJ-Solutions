#include <stdio.h>
#include <queue>
using namespace std;

int main() {
	int x, k;
	scanf("%d%d", &x, &k);
	// 10101 | 10 = 10101 + 10
	// 0000000000000000000000000000000010101 | 100000 = 10101 + 100000
	// 0, 10, 1000, 1010, 100000
	queue<int> q;
	for (int i = 0; x > 0; i++) {
		if (x & 1) q.push(i);
		x /= 2;
	}
	int i = 0;
	long long res = 0;
	while (k > 0) {
		if (!q.empty() && i == q.front()) {
			q.pop();
		}
		else {
			if (k & 1) res |= ((long long)1 << i);
			k /= 2;
		}
		i++;
	}
	printf("%lld", res);
}