#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin >> n;
	auto a = new int[n];
	map<int, int> m;
	set<int> s;
	for (int i = 0; i < n - 2; i++) {
		cin >> a[i];
		m[a[i]]++;
	}
	int idx = 1;
	for (auto const &now : m) {
		while (idx < now.first) {
			s.insert(idx);
			idx++;
		}
		idx++;
	}
	while (idx <= n) s.insert(idx++);
	vector<pair<int, int>> res;
	for (int i = 0; i < n - 2; i++) {
		if (m.empty() || s.empty()) {
			cout << -1;
			return 0;
		}
		int x = a[i], y = *s.rbegin();
		if (x == y) {
			cout << -1;
			return 0;
		}
		s.erase(y);
		auto it = m.find(x);
		if (it == m.end()) {
			cout << -1;
			return 0;
		}
		if (x > y) swap(x, y);
		res.emplace_back(x, y);
		it->second--;
		if (!it->second) {
			s.insert(it->first);
			m.erase(it);
		}
	}
	if (!m.empty() || s.size() != 2) {
		cout << -1;
		return 0;
	}
	res.emplace_back(1, *s.rbegin());
	sort(res.begin(), res.end());
	for (auto const& now : res) {
		cout << now.first << ' ' << now.second << '\n';
	}
}