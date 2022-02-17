#include <stdio.h>
#include <vector>
#include <utility>
using namespace std;
long long power(long long x) {
	if (x < 2) return x + 1;
	auto y = power(x / 2);
	return (((y * y) % 1000000) * (x % 2 ? 2 : 1)) % 1000000;
}

int main() {
	int n, a, b, c;
	scanf("%d%d%d%d", &n, &a, &b, &c);
	vector<pair<int, int>> v[3];
	int branch = 0;
	for (int i = 0; i < a; i++) {
		int x;
		scanf("%d", &x);
		if (v[0].empty()) {
			v[0].emplace_back(x, x);
		}
		else if (v[0].back().second == x + 1) {
			v[0].back().second--;
		}
		else {
			v[0].emplace_back(x, x);
		}
	}
	for (int i = 0; i < b; i++) {
		int x;
		scanf("%d", &x);
		if (x == n) {
			branch = 1;
		}
		if (v[1].empty()) {
			v[1].emplace_back(x, x);
		}
		else if (v[1].back().second == x + 1) {
			v[1].back().second--;
		}
		else {
			v[1].emplace_back(x, x);
		}
	}
	for (int i = 0; i < c; i++) {
		int x;
		scanf("%d", &x);
		if (x == n) {
			branch = 2;
		}
		if (v[2].empty()) {
			v[2].emplace_back(x, x);
		}
		else if (v[2].back().second == x + 1) {
			v[2].back().second--;
		}
		else {
			v[2].emplace_back(x, x);
		}
	}
	printf("%d\n", branch + 1);
	int arr[3] = { 0, 0, 0 };
	long long res = 0;
	while (true) {
		branch = 0;
		int big = 0;
		int cnt = 0;
		for (int i = 0; i < 3; i++) {
			if (arr[i] == v[i].size()) { cnt++; continue; }
			if (v[i][arr[i]].first > big) {
				big = v[i][arr[i]].first;
				branch = i;
			}
		}
		if (cnt >= 2) {
			printf("%lld", res);
			break;
		}
		res = (res + power(v[branch][arr[branch]++].second - 1) - 1) % 1000000;
	}
}