#include <iostream>
#include <memory>
#include <queue>
#include <utility>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, m;
	cin >> n >> m;
	auto prev = make_unique<unique_ptr<int[]>[]>(n);
	auto visited = make_unique<unique_ptr<bool[]>[]>(n);
	auto curr = make_unique<unique_ptr<int[]>[]>(n);
	for(int i = 0; i < n; i++) {
		prev[i] = make_unique<int[]>(m);
		curr[i] = make_unique<int[]>(m);
		visited[i] = make_unique<bool[]>(m);
		for(int j = 0; j < m; j++) {
			cin >> prev[i][j];
		}
	}
	int year = 0;
	while(true) {
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				curr[i][j] = prev[i][j];
				visited[i][j] = false;
			}
		}
		int cnt = 0;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				if(prev[i][j] && !visited[i][j]) {
					if(cnt == 1) {
						cout << year;
						return 0;
					}
					cnt++;
					queue<pair<int, int>> q;
					q.push({ i, j });
					while(!q.empty()) {
						auto const now = q.front(); q.pop();
						if(visited[now.first][now.second]) continue;
						visited[now.first][now.second] = true;
						if(now.first && prev[now.first - 1][now.second] && !visited[now.first - 1][now.second]) {
							q.push({ now.first - 1, now.second });
						}
						if(now.second && prev[now.first][now.second - 1] && !visited[now.first][now.second - 1]) {
							q.push({ now.first, now.second - 1 });
						}
						if(now.second < m - 1 && prev[now.first][now.second + 1] && !visited[now.first][now.second + 1]) {
							q.push({ now.first, now.second + 1 });
						}
						if(now.first < n - 1 && prev[now.first + 1][now.second] && !visited[now.first + 1][now.second]) {
							q.push({ now.first + 1, now.second });
						}
					}
				}
			}
		}
		if(!cnt) {
			cout << 0;
			return 0;
		}
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				visited[i][j] = false;
			}
		}
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				if(!prev[i][j]) {
					queue<pair<int, int>> q;
					q.push({ i, j });
					while(!q.empty()) {
						auto const now = q.front(); q.pop();
						if(visited[now.first][now.second]) continue;
						visited[now.first][now.second] = true;
						if(now.first && !visited[now.first - 1][now.second]) {
							if(prev[now.first - 1][now.second]) {
								if(curr[now.first - 1][now.second]) curr[now.first - 1][now.second]--;
							}
							else q.push({ now.first - 1, now.second });
						}
						if(now.second && !visited[now.first][now.second - 1]) {
							if(prev[now.first][now.second - 1]) {
								if(curr[now.first][now.second - 1]) curr[now.first][now.second - 1]--;
							}
							else q.push({ now.first, now.second - 1 });
						}
						if(now.second < m - 1 && !visited[now.first][now.second + 1]) {
							if(prev[now.first][now.second + 1]) {
								if(curr[now.first][now.second + 1]) curr[now.first][now.second + 1]--;
							}
							else q.push({ now.first, now.second + 1 });
						}
						if(now.first < n - 1 && !visited[now.first + 1][now.second]) {
							if(prev[now.first + 1][now.second]) {
								if(curr[now.first + 1][now.second]) curr[now.first + 1][now.second]--;
							}
							else q.push({ now.first + 1, now.second });
						}
					}
				}
			}
		}
		swap(prev, curr);
		year++;
	}
}