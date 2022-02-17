#include <stdio.h>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;
int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	auto a = new int[n];
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	queue<pair<int, int>> q;
	for (int i = 0; i < n; i++) {
		q.push({ a[i] - 1, -1 });
		q.push({ a[i] + 1, 1 });
	}
	int cnt = 0;
	set<int> s;
	for (int i = 0; i < n; i++) {
		s.insert(a[i]);
	}
	long long res = 0;
	while (cnt < k) {
		auto const now = q.front();
		q.pop();
		if (s.find(now.first) != s.end()) continue;
		s.insert(now.first);
		cnt++;
		res += abs(now.second);
		if (now.second < 0 && s.find(now.first - 1) == s.end()) {
			q.push({ now.first - 1, now.second - 1 });
		}
		else if (now.second > 0 && s.find(now.first + 1) == s.end()) {
			q.push({ now.first + 1, now.second + 1 });
		}
	}
	printf("%lld", res);
	delete[] a;
}