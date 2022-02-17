#include <iostream>
#include <numeric>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, m;
	cin >> n;
	auto s = new int[n];
	int sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
		sum += abs(i - s[i]);
	}
	cin >> m;
	while (m--) {
		int x, y;
		cin >> x >> y;
		sum -= abs(x - s[x]) + abs(y - s[y]);
		swap(s[x], s[y]);
		sum += abs(x - s[x]) + abs(y - s[y]);
		if (n == 2) {
			cout << (sum != 0) << ' ';
			continue;
		}
		cout << (sum == 0) - 1 << ' ';
	}
}