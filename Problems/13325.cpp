#include <algorithm>
#include <iostream>
#include <numeric>
#include <utility>
#include <vector>
using namespace std;
int dp(vector<pair<int, int>> const* v, int now, int& res) {
	if (v[now].empty()) return 0;
	int left = dp(v, v[now][0].first, res) + v[now][0].second;
	int right = dp(v, v[now][1].first, res) + v[now][1].second;
	res += abs(left - right);
	return max(left, right);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int k;
	cin >> k;
	int res = 0;
	auto v = new vector<pair<int, int>>[(1 << (k + 1)) - 1];
	for (int i = 0; i < (1 << (k + 1)) - 2; i++) {
		int x; cin >> x; res += x;
		v[i >> 1].push_back({ i + 1, x });
	}
	dp(v, 0, res);
	cout << res;
	delete[] v;
}