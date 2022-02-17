#include <iostream>
#include <vector>
using namespace std;
inline int depth(int n) {
	int d = 0;
	while (n) {
		n >>= 1;
		d++;
	}
	return d;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n; cin >> n;
	int d = depth(n - 1) - 1;
	vector<vector<int>> vs;
	while (d >= 0) {
		vector<int> v;
		for (int i = 1; i <= n; i++) {
			if (i & (1 << d)) v.push_back(i);
		}
		if (!v.empty()) vs.emplace_back(move(v));
		d--;
	}
	cout << vs.size() << '\n';
	for (auto const& v : vs) {
		cout << v.size();
		for (auto const now : v) {
			cout << ' ' << now;
		} cout << '\n';
	}
}