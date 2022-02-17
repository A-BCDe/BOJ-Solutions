#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
int main() {
	string s, t;
	cin >> s >> t;
	reverse(s.begin(), s.end());
	reverse(t.begin(), t.end());
	int i = 0;
	int c = 0;
	string res;
	while (i < s.size() && i < t.size()) {
		int const x = (s[i] - '0') + (t[i] - '0') + c;
		c = x / 10;
		res.push_back(x % 10 + '0');
		i++;
	}
	while (i < s.size()) {
		int const x = (s[i] - '0') + c;
		c = x / 10;
		res.push_back(x % 10 + '0');
		i++;
	}
	while (i < t.size()) {
		int const x = (t[i] - '0') + c;
		c = x / 10;
		res.push_back(x % 10 + '0');
		i++;
	}
	if (c) {
		res.push_back('1');
	}
	reverse(res.begin(), res.end());
	cout << res;
}