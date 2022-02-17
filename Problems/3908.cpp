#include <array>
#include <iostream>
#include <memory>
#include <vector>
using namespace std;
vector<int> make_prime() {
	bool visited[1121] = {};
	int i = 2;
	vector<int> v;
	while (i * i <= 1120) {
		if (!visited[i]) {
			v.push_back(i);
			for (int j = (i << 1); j <= 1120; j += i) visited[j] = true;
		}
		i++;
	}
	while (i <= 1120) {
		if (!visited[i]) v.push_back(i);
		i++;
	}
	return v;
}
int dp(unique_ptr<array<array<int, 15>, 1121>[]>& arr, vector<int> prime, int n, int k) {
	int sum = 0;
	for (int i = 0; i < prime.size(); i++) {
		if (arr[i][n][k] != -1) {
			sum += arr[i][n][k];
			continue;
		}
		if (k == 0) {
			sum += (arr[i][n][0] = (n == 0));
			continue;
		}
		if (k == 1) {
			sum += (arr[i][n][1] = (n == i));
			continue;
		}
		if (n >= prime[i]) {
			sum += (arr[i][n][k] = dp(arr, prime, n - prime[i], k - 1));
		}
	}
	return sum;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t;
	cin >> t;
	auto prime = make_prime();
	auto a = make_unique<array<array<int, 15>, 1121>[]>(prime.size());
	for (int i = 0; i < prime.size(); i++) {
		for (auto& j : a[i]) {
			for (auto& k : j) {
				k = -1;
			}
		}
	}
	while (t--) {
		int n, k;
		cin >> n >> k;
		cout << dp(a, prime, n, k) << '\n';
	}
}