#include <iostream>
using namespace std;
inline int dist(pair<int, int> const &a, pair<int, int> const &b) {
	return abs(a.first - b.first) + abs(a.second - b.second);
}
void print(pair<int, int> **prev, pair<int, int> pair) {
	if(!pair.first && pair.second == 1) return;
	print(prev, prev[pair.first][pair.second]);
	cout << (pair.first > pair.second ? 1 : 2) << '\n';
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n, w;
	cin >> n >> w;
	auto a = new pair<int, int>[w + 2];
	a[0] = { 1, 1 };
	a[1] = { n, n };
	for(int i = 2; i < w + 2; i++) {
		cin >> a[i].first >> a[i].second;
	}
	auto dp = new int*[w + 2];
	auto prev = new pair<int, int>*[w + 2];
	for(int i = 0; i < w + 2; i++) {
		dp[i] = new int[w + 2]();
		prev[i] = new pair<int, int>[w + 2]();
	}
	for(int i = 2; i < w + 2; i++) {
		// C1 = 0
		dp[0][i] = dp[0][i - 1] + dist(a[i], a[i - 1]);
		prev[0][i] = { 0, i - 1 };
		// C1 >= 2
		for(int j = 2; j < i - 1; j++) {
			dp[j][i] = dp[j][i - 1] + dist(a[i], a[i - 1]);
			prev[j][i] = { j, i - 1 };
		}
		if(i > 2) {
			dp[i - 1][i] = dp[i - 1][1] + dist(a[i], a[1]);
			prev[i - 1][i] = { i - 1, 1 };
			for(int j = 2; j <= i - 2; j++) {
				int const x = dp[i - 1][j] + dist(a[i], a[j]);
				if(dp[i - 1][i] > x) {
					dp[i - 1][i] = x;
					prev[i - 1][i] = { i - 1, j };
				}
			}
		}
		// C2 >= 1
		for(int j = 1; j < i - 1; j++) {
			dp[i][j] = dp[i - 1][j] + dist(a[i], a[i - 1]);
			prev[i][j] = { i - 1, j };
		}
		dp[i][i - 1] = dp[0][i - 1] + dist(a[i], a[0]);
		prev[i][i - 1] = { 0, i - 1 };
		for(int j = 2; j <= i - 2; j++) {
			int const x = dp[j][i - 1] + dist(a[i], a[j]);
			if(dp[i][i - 1] > x) {
				dp[i][i - 1] = x;
				prev[i][i - 1] = { j, i - 1 };
			}
		}
	}
	int res = dp[0][w + 1];
	pair<int, int> resp = { 0, w + 1 };
	for(int i = 2; i < w + 1; i++) {
		if(res > dp[i][w + 1]) {
			res = dp[i][w + 1];
			resp = { i, w + 1 };
		}
	}
	for(int i = 1; i < w + 1; i++) {
		if(res > dp[w + 1][i]) {
			res = dp[w + 1][i];
			resp = { w + 1, i };
		}
	}
	cout << res << '\n';
	print(prev, resp);
}