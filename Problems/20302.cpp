#include <algorithm>
#include <stdio.h>
#include <vector>
using namespace std;
vector<int> prime() {
	auto visited = new bool[100001]();
	vector<int> v;
	int i;
	for (i = 2; i * i < 100001; i++) {
		if (!visited[i]) {
			v.push_back(i);
			for (int j = (i << 1); j < 100001; j += i) {
				visited[j] = true;
			}
		}
	}
	for (; i < 100001; i++) {
		if (!visited[i]) v.push_back(i);
	}
	delete[] visited;
	return v;
}
void insert(vector<int> const& primes, int* a, int x) {
	for (int i = 0; primes[i] * primes[i] <= x; i++) {
		while (x % primes[i] == 0) {
			a[i]++;
			x /= primes[i];
		}
		if (x == 1) return;
	}
	a[lower_bound(primes.begin(), primes.end(), x) - primes.begin()]++;
}
int main() {
	auto const primes = prime();
	int n;
	scanf("%d", &n);
	auto mul = new int[primes.size()]();
	auto div = new int[primes.size()]();
	int x;
	scanf("%d", &x);
	if (!x) {
		printf("mint chocolate");
		return 0;
	}
	insert(primes, mul, x > 0 ? x : -x);
	while (--n) {
		char c[2];
		scanf("%s%d", c, &x);
		if (*c == '*') {
			if (!x) {
				printf("mint chocolate");
				return 0;
			}
			insert(primes, mul, x > 0 ? x : -x);
		}
		else insert(primes, div, x > 0 ? x : -x);
	}
	for (int i = 0; i < primes.size(); i++) {
		if (mul[i] < div[i]) {
			printf("toothpaste");
			return 0;
		}
	}
	printf("mint chocolate");
}