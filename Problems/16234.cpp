#include <algorithm>
#include <cmath>
#include <cstdio>
#include <utility>
#include <vector>
using namespace std;
void append(vector<pair<int, int>> &res, vector<pair<int, int>> const &vec) {
	auto size = res.size();
	res.resize(size + vec.size());
	copy(vec.begin(), vec.end(), res.begin() + size);
}
pair<int, vector<pair<int, int>>> dfs(int **a, bool **visited, int n, int l, int r, int x, int y) {
	visited[x][y] = true;
	int res = a[x][y];
	vector<pair<int, int>> resvec = {{x, y}};
	if(x && !visited[x - 1][y] && abs(a[x - 1][y] - a[x][y]) >= l && abs(a[x - 1][y] - a[x][y]) <= r) {
		auto [val, vec] = dfs(a, visited, n, l, r, x - 1, y);
		res += val;
		append(resvec, vec);
	}
	if(y && !visited[x][y - 1] && abs(a[x][y - 1] - a[x][y]) >= l && abs(a[x][y - 1] - a[x][y]) <= r) {
		auto [val, vec] = dfs(a, visited, n, l, r, x, y - 1);
		res += val;
		append(resvec, vec);
	}
	if(x < n - 1 && !visited[x + 1][y] && abs(a[x + 1][y] - a[x][y]) >= l && abs(a[x + 1][y] - a[x][y]) <= r) {
		auto [val, vec] = dfs(a, visited, n, l, r, x + 1, y);
		res += val;
		append(resvec, vec);
	}
	if(y < n - 1 && !visited[x][y + 1] && abs(a[x][y + 1] - a[x][y]) >= l && abs(a[x][y + 1] - a[x][y]) <= r) {
		auto [val, vec] = dfs(a, visited, n, l, r, x, y + 1);
		res += val;
		append(resvec, vec);
	}
	return { res, resvec };
}
int main() {
	int n, l, r;
	scanf("%d%d%d", &n, &l, &r);
	auto a = new int*[n];
	auto visited = new bool*[n];
	for(int i = 0; i < n; i++) {
		a[i] = new int[n];
		visited[i] = new bool[n];
		for(int j = 0; j < n; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	int cnt = 0;
	while(true) {
		for(int i = 0; i < n; i++) { for(int j = 0; j < n; j++) printf("%d ", a[i][j]); printf("\n"); } printf("\n");
		bool flag = false;
		for(int i = 0; i < n; i++) fill(visited[i], visited[i] + n, false);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if(visited[i][j]) continue;
				if(i && !visited[i - 1][j] && abs(a[i - 1][j] - a[i][j]) >= l && abs(a[i - 1][j] - a[i][j]) <= r) goto NEXT;
				if(j && !visited[i][j - 1] && abs(a[i][j - 1] - a[i][j]) >= l && abs(a[i][j - 1] - a[i][j]) <= r) goto NEXT;
				if(i < n - 1 && !visited[i + 1][j] && abs(a[i + 1][j] - a[i][j]) >= l && abs(a[i + 1][j] - a[i][j]) <= r) goto NEXT;
				if(j < n - 1 && !visited[i][j + 1] && abs(a[i][j + 1] - a[i][j]) >= l && abs(a[i][j + 1] - a[i][j]) <= r) goto NEXT;
				visited[i][j] = true;
				continue;
			NEXT:
				flag = true;
				auto [val, vec] = dfs(a, visited, n, l, r, i, j);
				auto const res = val / vec.size();
				for(auto [x, y] : vec) {
					a[x][y] = res;
				}
			}
		}
		if(!flag) {
			printf("%d", cnt);
			return 0;
		}
		cnt++;
	}
}