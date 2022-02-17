#include <iostream>
#include <string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int tt; cin >> tt;
	char map[26];
	while (tt--) {
		string s; cin >> s;
		int n; cin >> n;
		auto cnt = s.size();
		string res;
		while (n--) {
			fill(map, map + 26, (char)0);
			int cur = 0;
			bool flag = false;
			string t; cin >> t;
			for (int i = 0; i < s.size(); i++) {
				if (s[i] != t[i]) {
					if (!map[t[i] - 'a']) {
						map[t[i] - 'a'] = s[i];
					}
					else if (map[t[i] - 'a'] != s[i]) {
						flag = true;
						break;
					}
					cur++;
				}
			}
			if (flag) continue;
			if (cnt > cur || res.empty()) {
				cnt = cur;
				res = t;
			}
			else if (cnt == cur && t < res) {
				res = t;
			}
		}
		cout << res << '\n';
	}
}