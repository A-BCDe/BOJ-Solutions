#include <iostream>
#include <numeric>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, m, k;
	cin >> n >> m >> k;
	auto a = new int[n * m];
	auto dp = new int**[k + 1];
	for (int i = 0; i < n * m; i++) cin >> a[i];
	for (int i = 0; i <= k; i++) {
		dp[i] = new int*[n * m];
		for (int j = 0; j < n * m; j++) {
			dp[i][j] = new int[1 << m]();
		}
	}/*
	for (int j = 0; j < n * m; j++) {
		int x = 1;
		if (j % m != m - 1) x |= (1 << (m - 1));
		dp[1][j][x] = a[j];
	}*/
	for (int i = 1; i <= k; i++) {
		for (int j = 0; j < n * m; j++) {
			for (int l = 0; l < (1 << m); l++) {
				if (l & 1) { // j번째 칸을 선택한다
					
				}
				else { // 선택하지 않는다
					
				}
			}
		}
	}
}