#include <algorithm>
#include <stdio.h>
#include <vector>
using namespace std;
vector<int> prime(int n) {
	auto visited = new bool[n + 1]();
	vector<int> v;
	for (int i = 2; i <= n; i++) {
		if (!visited[i]) {
			v.push_back(i);
			for (int j = (i << 1); j <= n; j += i) {
				visited[j] = true;
			}
		}
	}
	delete[] visited;
	return v;
}
int main() {
	int n;
	scanf("%d", &n);
	if (n < 8) {
		printf("-1");
		return 0;
	}
	printf("2 ");
	if (n & 1) n -= 5, printf("3 ");
	else n -= 4, printf("2 ");
	auto primes = prime(n);
	for (auto p : primes) {
		auto ptr = lower_bound(primes.begin(), primes.end(), n - p);
		if (ptr == primes.end() || *ptr + p != n) continue;
		printf("%d %d", p, (int)(*ptr));
		return 0;
	}
}