#include <iostream>
#include <string>
using namespace std;
bool dfs(long long dst, long long now, string& s) {
	if (dst == now) return true;
	if (!s.empty() && dst < now) return false;
	string res;
	string t = s + "+";
	if (dfs(dst, now * 2, t)) res = t;
	if (now != 1) {
		t = s + "*";
		if (dfs(dst, now * now, t) && (res.empty() || (res.size() > t.size() || (res.size() == t.size() && res > t)))) res = t;
	}
	if (s.empty()) {
		t = "/";
		if (dfs(dst, 1, t) && (res.empty() || (res.size() > t.size() || (res.size() == t.size() && res > t)))) res = t;
	}
	s = res;
	return !res.empty();
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int x, y;
	cin >> x >> y;
	if (x == y) {
		cout << 0;
		return 0;
	}
	string s;
	if (dfs(y, x, s)) cout << s;
	else cout << -1;
}