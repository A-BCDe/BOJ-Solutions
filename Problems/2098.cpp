#include <iostream>
using namespace std;
constexpr int M = 20000000;
int f(int **dp, int **dist, int n, int cur, int visited) {
	if(dp[cur][visited] != -1) return dp[cur][visited];
	if(visited == (1 << n) - 2) { // 111...110
		return dp[cur][visited] = dist[cur][0];
	}
	int res = M;
	for(int i = 1; i < n; i++) {
		if(!(visited & (1 << i))) {
			int const x = f(dp, dist, n, i, visited | (1 << i)) + dist[cur][i];
			if(res > x) res = x;
		}
	}
	return dp[cur][visited] = res;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n;
	cin >> n;
	auto dist = new int*[n];
	auto dp = new int*[n];
	for(int i = 0; i < n; i++) {
		dp[i] = new int[1 << n];
		fill(dp[i], dp[i] + (1 << n), -1);
		dist[i] = new int[n];
		for(int j = 0; j < n; j++) {
			cin >> dist[i][j];
			if(!dist[i][j]) dist[i][j] = M;
		}
	}
	int res = M;
	for(int i = 1; i < n; i++) {
		int const x = f(dp, dist, n, i, 1 << i) + dist[0][i];
		if(res > x) res = x;
	}
	cout << res;
}