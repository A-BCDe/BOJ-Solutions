#include <stdio.h>
#include <utility>
#include <vector>
using namespace std;
int dfs(int** a, vector<pair<pair<int, int>, int>> const& v, bool* visited, int n, int m, int k, int cur) {
	if (cur == k) {
		int min = 10000;
		for (int i = 0; i < n; i++) {
			int sum = 0;
			for (int j = 0; j < m; j++) {
				sum += a[i][j];
			}
			if (min > sum) min = sum;
		}
		return min;
	}
	int min = 10000;
	for (int i = 0; i < k; i++) {
		if (visited[i]) continue;
		visited[i] = true;
		auto b = new int* [n];
		pair<pair<int, int>, int> const& p = v[i];
		for (int j = 0; j < n; j++) {
			b[j] = new int[m];
			copy(a[j], a[j] + m, b[j]);
		}
		for (int x = 1; x <= p.second; x++) {
			for (int y = -x; y < x; y++) {
				b[p.first.first - x][p.first.second + y + 1] = a[p.first.first - x][p.first.second + y];
				b[p.first.first + y + 1][p.first.second + x] = a[p.first.first + y][p.first.second + x];
				b[p.first.first + x][p.first.second - y - 1] = a[p.first.first + x][p.first.second - y];
				b[p.first.first - y - 1][p.first.second - x] = a[p.first.first - y][p.first.second - x];
			}
		}
		auto const res = dfs(b, v, visited, n, m, k, cur + 1);
		if (min > res) min = res;
		delete[] b;
		visited[i] = false;
	}
	return min;
}
int main() {
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	auto a = new int* [n];
	for (int i = 0; i < n; i++) {
		a[i] = new int[m];
		for (int j = 0; j < m; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	vector<pair<pair<int, int>, int>> v;
	for (int i = 0; i < k; i++) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		v.emplace_back(make_pair(x - 1, y - 1), z);
	}
	auto visited = new bool[k]();
	printf("%d", dfs(a, v, visited, n, m, k, 0));
	delete[] visited;
	for (int i = 0; i < n; i++) delete[] a[i];
	delete[] a;
}