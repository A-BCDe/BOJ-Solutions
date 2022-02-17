#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	auto v = new vector<pair<long long, int>>[n + 1];
	for (int i = 0; i < m; i++) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		v[a].emplace_back(c, b);
	}
	int s, e;
	scanf("%d%d", &s, &e);
	auto prev = new int[n + 1]();
	priority_queue<pair<long long, pair<int, int>>> pq;
	for (auto&& now : v[s]) {
		pq.push(make_pair(-now.first, make_pair(s, now.second)));
	}
	while (!pq.empty()) {
		auto const now = pq.top(); pq.pop();
		if (prev[now.second.second]) continue;
		prev[now.second.second] = now.second.first;
		if (now.second.second == e) {
			printf("%lld\n", -now.first);
			int x = e;
			stack<int> st;
			while (x != s) {
				st.push(x);
				x = prev[x];
			}
			st.push(s);
			cout << st.size() << endl;
			while (!st.empty()) {
				printf("%d ", st.top());
				st.pop();
			}
			return 0;
		}
		for (auto&& next : v[now.second.second]) {
			if (!prev[next.second]) pq.push(make_pair(now.first - next.first, make_pair(now.second.second, next.second)));
		}
	}
	delete[] v;
	delete[] prev;
}