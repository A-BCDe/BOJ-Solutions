#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
int** a;
struct comp {
	bool operator()(pair<int, int> const& x, pair<int, int> const& y) {
		return a[x.first][x.second] < a[y.first][y.second];
	}
};
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin >> n;
	a = new int* [n];
	for (int i = 0; i < n; i++) {
		a[i] = new int[n];
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	priority_queue<pair<int, int>, vector<pair<int, int>>, comp> pq;
	for (int j = 0; j < n; j++) {
		pq.push({ n - 1, j });
	}
	for (int i = 0; i < n - 1; i++) {
		auto const now = pq.top();
		pq.pop();
		if (now.first == 0) continue;
		pq.push({ now.first - 1, now.second });
	}
	printf("%d", a[pq.top().first][pq.top().second]);
}