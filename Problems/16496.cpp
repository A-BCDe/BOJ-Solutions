#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main() {
	int n;
	cin >> n;
	auto s = new string[n];
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}
	sort(s, s + n, [](string const& a, string const& b) {
		auto x = a + b;
		auto y = b + a;
		return x > y;
	});
	int i = 0;
	while (i < n && s[i] == "0") i++;
	if (i == n) {
		cout << '0';
	}
	else {
		for (; i < n; i++) {
			cout << s[i];
		}
	}
	delete[] s;
}