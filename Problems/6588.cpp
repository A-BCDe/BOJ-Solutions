#include <algorithm>
#include <stdio.h>
#include <vector>
using namespace std;
constexpr int N = 1000000;
inline vector<int> make_primes() {
	vector<int> primes;
	vector<bool> visited(N + 1);
	for(int i = 2; i <= N; i++) {
		if(!visited[i]) {
			primes.push_back(i);
			for(int j = (i << 1); j <= N; j += i) {
				visited[j] = true;
			}
		}
	}
	return primes;
}
int main() {
	int n;
	auto primes = make_primes();
	while(true) {
		scanf("%d", &n);
		if(!n) return 0;
		for(int i = 0; i < primes.size(); i++) {
			if(binary_search(primes.begin(), primes.end(), n - primes[i])) {
				printf("%d = %d + %d\n", n, primes[i], n - primes[i]);
				break;
			}
		}
	}
}