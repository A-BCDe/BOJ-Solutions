#include <algorithm>
#include <iostream>
#include <utility>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, x;
	cin >> n >> x;
	x /= 1000; // z <= x / 5
	auto a = new pair<int, int>[n];
	int const mx = x / 5;
	int cnt = 0;
	for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
	sort(a, a + n, [](pair<int, int> const& a, pair<int, int> const& b) {
		return max(a.first, a.second) > max(b.first, b.second);
	});
	int sum = 0;
	for (int i = 0; i < n; i++) {
		if (cnt == mx) {
			sum += a[i].second;
			continue;
		}
		if (a[i].first > a[i].second) {
			sum += a[i].first;
			cnt++;
		}
		else sum += a[i].second;
	}
	printf("%d", sum);
}