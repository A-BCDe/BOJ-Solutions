#include <stdio.h>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
vector<int> prime() {
	auto visited = new bool[10001]();
	vector<int> v;
	for (int i = 2; i < 10000; i++) {
		if (!visited[i]) {
			if(i > 1000) v.push_back(i);
			for (int j = (i << 1); j < 10000; j += i) {
				visited[j] = true;
			}
		}
	}
	delete[] visited;
	return v;
}
bool check(int a, int b) {
	int cnt = 0;
	while (a) {
		cnt += (a % 10 != b % 10);
		a /= 10; b /= 10;
	}
	return cnt == 1;
}
int main() {
	auto primes = prime();
	auto v = new vector<int>[10000];
	for (int i = 0; i < primes.size(); i++) {
		for (int j = i + 1; j < primes.size(); j++) {
			if (check(primes[i], primes[j])) {
				v[primes[i]].push_back(primes[j]);
				v[primes[j]].push_back(primes[i]);
			}
		}
	}
	int t;
	scanf("%d", &t);
	auto visited = new bool[10000];
	while (t--) {
		fill(visited, visited + 10000, false);
		int x, y;
		scanf("%d%d", &x, &y);
		queue<pair<int, int>> q;
		q.push({ x, 0 });
		while (!q.empty()) {
			auto const now = q.front(); q.pop();
			if (visited[now.first]) continue;
			visited[now.first] = true;
			if (now.first == y) {
				printf("%d\n", now.second);
				goto END;
			}
			for (auto next : v[now.first]) {
				if (visited[next]) continue;
				q.push({ next, now.second + 1 });
			}
		}
		printf("Impossible\n");
	END:;
	}
}