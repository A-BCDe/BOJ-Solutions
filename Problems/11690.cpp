#include <stdio.h>
constexpr long long M = ((long long)(1) << 32);
int main() {
	int n;
	scanf("%d", &n);
	auto visited = new bool[n + 1]();
	long long ans = 1;
	int i;
	for (i = 2; i * i <= n; i++) {
		if (!visited[i]) {
			for (int j = (i << 1); j <= n; j += i) {
				visited[j] = true;
			}
			long long x = i;
			while (x < n) {
				x *= i;
			}
			ans = (ans * (x / i)) % M;
		}
	}
	while (i <= n) {
		if (!visited[i]) {
			ans = (ans * i) % M;
		}
		i++;
	}
	printf("%lld", ans);
	delete[] visited;
}