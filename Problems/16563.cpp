#include <iostream>
#include <vector>
using namespace std;
constexpr int M = 1000001;
vector<int> prime() {
	auto visited = new bool[M]();
	vector<int> v;
	int i;
	for (i = 2; i * i < M; i++) {
		if (!visited[i]) {
			v.push_back(i);
			for (int j = (i << 1); j < M; j += i) {
				visited[j] = true;
			}
		}
	}
	for (; i < M; i++) {
		if (!visited[i]) v.push_back(i);
	}
	delete[] visited;
	return v;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	auto primes = prime();
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		for (auto p : primes) {
			if (p * p > n) {
				printf("%d\n", n);
				break;
			}
			while (n % p == 0) {
				n /= p;
				printf("%d ", p);
			}
			if (n == 1) {
				printf("\n");
				break;
			}
		}
	}
}