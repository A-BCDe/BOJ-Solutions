#include <algorithm>
#include <stdio.h>
#include <vector>
std::vector<int> prime() {
	std::vector<int> primes;
	auto visited = new bool[10000]();
	for(int i = 2; i < 10000; i++) {
		if(!visited[i]) {
			primes.push_back(i);
			for(int j = (i << 1); j < 10000; j += i) {
				visited[j] = true;
			}
		}
	}
	delete[] visited;
	return primes;
}
int main() {
	auto primes = prime();
	int t;
	scanf("%d", &t);
	while(t--) {
		int n, res = 0;
		scanf("%d", &n);
		for(int i = 0; i < primes.size(); i++) {
			auto p = std::lower_bound(primes.begin() + i, primes.end(), n - primes[i]);
			if(p == primes.end() || *p != n - primes[i]) continue;
			res = primes[i];
		}
		printf("%d %d\n", res, n - res);
	}
}