#include <iostream>
#include <set>
#include <vector>
using namespace std;
int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	while (true) {
		cin >> n;
		if (n == 0) return 0;
		auto a = new int[n];
		set<int> s;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			if (s.empty()) {
				s.insert(a[i]);
				continue;
			}
			vector<int> v;
			v.reserve(s.size());
			for (auto it = s.begin(); it != s.end(); ++it) {
				v.push_back(gcd(*it, a[i]));
			}
			for (auto now : v) {
				s.insert(now);
			}
			s.insert(a[i]);
		}
		cout << s.size() << '\n';
		delete[] a;
	}
}