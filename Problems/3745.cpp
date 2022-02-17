#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	while (cin >> n) {
		int x; vector<int> v;
		for (int i = 0; i < n; i++) {
			cin >> x;
			if (v.empty() || v.back() < x) v.push_back(x);
			*lower_bound(v.begin(), v.end(), x) = x;
		}
		cout << v.size() << '\n';
	}
}