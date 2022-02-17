#include <stdio.h>
#include <algorithm>
#include <queue>
#include <utility>
using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	auto a = new pair<int, int>[n];
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &a[i].first, &a[i].second);
	}
	sort(a, a + n);
	priority_queue<int> pq;
	for (int i = 0; i < n; i++) {
		if (pq.size() < a[i].first) {
			pq.push(-a[i].second);
		}
		else if (pq.size() >= a[i].first && a[i].second > -pq.top()) {
			pq.pop();
			pq.push(-a[i].second);
		}
	}
	int res = 0;
	while (!pq.empty()) {
		res -= pq.top();
		pq.pop();
	}
	printf("%d", res);
	delete[] a;
}