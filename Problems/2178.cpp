#include <iostream>
#include <queue>
#include <string>
#include <utility>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, m;
	cin >> n >> m;
	auto a = new string[n];
	auto visited = new bool*[n];
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		visited[i] = new bool[m]();
	}
	queue<pair<pair<int, int>, int>> q;
	q.push({{0, 0}, 0});
	while(!q.empty()) {
		auto const now = q.front(); q.pop();
		if(visited[now.first.first][now.first.second]) continue;
		visited[now.first.first][now.first.second] = true;
		if(now.first.first == n - 1 && now.first.second == m - 1) {
			cout << now.second + 1;
			return 0;
		}
		if(now.first.first && a[now.first.first - 1][now.first.second] == '1' && !visited[now.first.first - 1][now.first.second]) {
			q.push({{now.first.first - 1, now.first.second}, now.second + 1});
		}
		if(now.first.second && a[now.first.first][now.first.second - 1] == '1' && !visited[now.first.first][now.first.second - 1]) {
			q.push({{now.first.first, now.first.second - 1}, now.second + 1});
		}
		if(now.first.first < n - 1 && a[now.first.first + 1][now.first.second] == '1' && !visited[now.first.first + 1][now.first.second]) {
			q.push({{now.first.first + 1, now.first.second}, now.second + 1});
		}
		if(now.first.second < m - 1 && a[now.first.first][now.first.second + 1] == '1' && !visited[now.first.first][now.first.second + 1]) {
			q.push({{now.first.first, now.first.second + 1}, now.second + 1});
		}
	}
	delete[] a;
}