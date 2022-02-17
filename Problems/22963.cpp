#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin >> n;
	auto a = new int[n];
	auto piv = new int[n];
	vector<int> v;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (v.empty() || v.back() < a[i]) {
			v.push_back(a[i]);
			piv[i] = i;
			continue;
		}
		auto p = lower_bound(v.begin(), v.end(), a[i]);
		piv[i] = p - v.begin();
		*p = a[i];
	}
	cout << v.size();
}