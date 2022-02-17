#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
string add(string& a, string& b) {
	string res;
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	int idx = 0, c = 0;
	while (idx < a.size() && idx < b.size()) {
		int const x = a[idx] - '0' + b[idx] - '0' + c;
		res.push_back(x % 10 + '0');
		c = x / 10;
		idx++;
	}
	while (idx < a.size()) {
		int const x = a[idx] - '0' + c;
		res.push_back(x % 10 + '0');
		c = x / 10;
		idx++;
	}
	while (idx < b.size()) {
		int const x = b[idx] - '0' + c;
		res.push_back(x % 10 + '0');
		c = x / 10;
		idx++;
	}
	if (c) {
		res.push_back('1');
	}
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	reverse(res.begin(), res.end());
	return res;
}
int main() {
	int n;
	cin >> n;
	string a = "0", b = "1";
	if (n == 1) {
		printf("0");
		return 0;
	}
	if (n == 2) {
		printf("1");
		return 0;
	}
	int idx = 2;
	while (idx < n) {
		auto tmp = add(a, a);
		tmp = add(tmp, b);
		a = move(b);
		b = move(tmp);
		idx++;
	}
	cout << b;
}