#include <iostream>
#include <string>
using namespace std;
int dfs(string const* a, int* const* visited, int n, int m, int x, int y) {
	if (x >= n || x < 0 || y >= m || y < 0) return 0;
	if (visited[x][y] > 0) return 0;
	if (visited[x][y] < 0) return -1;
	int const nx = x, ny = y;
	visited[x][y] = -2;
	if (a[x][y] == 'U') x--;
	else if (a[x][y] == 'R') y++;
	else if (a[x][y] == 'D') x++;
	else if (a[x][y] == 'L') y--;
	int res = dfs(a, visited, n, m, x, y);
	if (res == -1) return visited[nx][ny] = -1;
	return visited[nx][ny] = res + 1;
}
int main() {
	int n, m;
	cin >> n >> m;
	auto a = new string[n];
	auto visited = new int*[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		visited[i] = new int[m]();
	}
	int res = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int const x = dfs(a, visited, n, m, i, j);
			if (x != -1) res += x;
		}
	}
	cout << res;
	for (int i = 0; i < n; i++) delete[] visited[i];
	delete[] visited;
	delete[] a;
}