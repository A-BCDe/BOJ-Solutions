#include <stdio.h>
#include <vector>
using namespace std;
int dfs(vector<int> const* v, int now, int m) {
	if (v[now].empty() || (v[now].size() == 1 && v[now][0] == m)) return 1;
	int sum = 0;
	for (auto next : v[now]) {
		if (next == m) continue;
		sum += dfs(v, next, m);
	}
	return sum;
}
int main() {
	int root, n;
	scanf("%d", &n);
	auto a = new int[n];
	auto v = new vector<int>[n];
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		if (a[i] == -1) { root = i; continue; }
		v[a[i]].push_back(i);
	}
	int m;
	scanf("%d", &m);
	if (root == m) {
		printf("0");
		return 0;
	}
	printf("%d", dfs(v, root, m));
}