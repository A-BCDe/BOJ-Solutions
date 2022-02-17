#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
int main() {
	string s, t;
	cin >> s >> t;
	auto a = new int*[s.size() + 1];
	for(int i = 0; i <= s.size(); i++) {
		a[i] = new int[t.size() + 1]();
	}
	for(int i = 1; i <= s.size(); i++) {
		for(int j = 1; j <= t.size(); j++) {
			int res = a[i - 1][j - 1] + (s[i - 1] == t[j - 1]);
			res = max(res, a[i - 1][j]);
			res = max(res, a[i][j - 1]);
			a[i][j] = res;
		}
	}
	cout << a[s.size()][t.size()] << '\n';
	/*
	for(int i = 0; i <= s.size(); i++) {
		for(int j = 0; j <= t.size(); j++) {
			cout << a[i][j] << ' ';
		} cout << '\n';
	} cout << '\n';
*/
	string res;
	auto x = s.size(), y = t.size();
	while(x && y) {
		if(a[x - 1][y] == a[x][y]) x--;
		else if(a[x][y - 1] == a[x][y]) y--;
		else if(a[x - 1][y - 1] == a[x][y]) x--, y--;
		else if(a[x - 1][y - 1] + 1 == a[x][y]) res += s[--x], y--;
	}
	reverse(res.begin(), res.end());
	cout << res;
}