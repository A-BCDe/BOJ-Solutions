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
	auto map = new int[n + 1];
	auto b = new int[n + 1];
	for(int i = 1; i <= n; i++) {
		int x; cin >> x;
		map[x] = i;
	}
	for(int i = 1; i <= n; i++) {
		int x; cin >> x;
		b[i] = map[x];
	}
	vector<int> v;
	for(int i = 1; i <= n; i++) {
		if(v.empty() || v.back() < b[i]) {
			v.push_back(b[i]);
			continue;
		}
		auto p = lower_bound(v.begin(), v.end(), b[i]);
		*p = b[i];
	}
	cout << v.size();
	delete[] map;
	delete[] b;
}