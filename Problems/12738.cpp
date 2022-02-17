#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (v.empty() || v.back() < x) {
			v.push_back(x);
			continue;
		}
		auto p = lower_bound(v.begin(), v.end(), x);
		*p = x;
	}
	cout << v.size();
}