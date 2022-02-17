#include <stdio.h>
void dfs(bool* visited, int n, int m, int idx, int cnt) {
	if (idx > n || m < cnt) return;
	if (m == cnt) {
		for (int i = 0; i < n; i++) {
			if (visited[i]) printf("%d ", i + 1);
		}
		printf("\n");
		return;
	}
	visited[idx] = true;
	dfs(visited, n, m, idx + 1, cnt + 1);
	visited[idx] = false;
	dfs(visited, n, m, idx + 1, cnt);
}
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	auto visited = new bool[n + 1]();
	dfs(visited, n, m, 0, 0);
	delete[] visited;
}