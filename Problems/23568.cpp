#include <iostream>
#include <map>
using namespace std;
using ll = long long;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n; cin >> n;
	ll i, k; char j[2];
	map<ll, ll> m;
	while (n--) {
		cin >> i >> j >> k;
		if (*j == 'L') k = -k;
		m[i] = k;
	}
	ll cur; cin >> cur;
	do {
		auto it = m.find(cur);
		if (it == m.end()) {
			cout << cur;
			return 0;
		}
		cur += it->second;
	} while (true);
}	