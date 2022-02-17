#include <stdio.h>
#include <vector>
#include <queue>
#include <utility>
#include <set>
using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	auto s = new set<int>[n + 1];
	auto visited = new bool[n + 1]();
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		s[a].insert(b);
		s[b].insert(a);
	}
	queue<pair<int, int>> q;
	q.push(make_pair(1, 0));
	auto a = new int[n + 1]();
	while (!q.empty()) {
		auto const now = q.front(); q.pop();
		if (visited[now.first]) continue;
		visited[now.first] = true;
		a[now.first] = now.second;
		for (auto const next : s[now.first]) {
			if (!visited[next]) {
				s[next].erase(now.first);
				q.push(make_pair(next, now.second + 1));
			}
		}
	}
	delete[] visited;
	visited = new bool[n + 1]();
	vector<int> v;
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		v.push_back(x);
	}
	int piv = 1;
	for (int i = 0; i < n; i++) {
		auto const now = v[i];
		for (auto j = 0; j < s[now].size(); j++) {
			if (s[now].find(v[piv]) == s[now].end()) {
				printf("0");
				return 0;
			}
			piv++;
		}
	}
	printf("1");
}