#include <stdio.h>
#include <vector>
#include <set>
using namespace std;
int dfs(int cur, int depth, vector<int>* v, set<int>& s) {
	if (depth == 4) return 4;
	s.insert(cur);
	int max = depth;
	for (auto now : v[cur]) {
		if (s.find(now) == s.end()) {
			auto x = dfs(now, depth + 1, v, s);
			s.erase(now);
			if (x == 4) {
				return 4;
			}
			else if (max < x) max = x;
		}
	}
	return max;
}
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	auto v = new vector<int>[n];
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int i = 0; i < n; i++) {
		set<int> s;
		if (dfs(i, 0, v, s) == 4) {
			printf("1");
			goto CLEAN;
		}
	}
	printf("0");
CLEAN:
	delete[] v;
}