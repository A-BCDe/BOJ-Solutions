#include <stdio.h>
using ll = long long;
constexpr ll M = 1000007;
constexpr ll n = 401;
int main() {
	auto C = new ll*[n];
	for (int i = 0; i < n; i++) {
		C[i] = new ll[i + 1]();
		C[i][0] = C[i][i] = 1;
		for (int j = 1; j < i; j++) {
			C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % M;
		}
	}
	int a, b, c, d;
	scanf("%d%d%d%d", &a, &b, &c, &d);
	a--; b--; c--; d--;
	printf("%lld", (C[c + d][d] * C[a + b - c - d][a - c]) % M);
}