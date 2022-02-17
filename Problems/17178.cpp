#include <iostream>
#include <algorithm>
#include <stack>
#include <utility>
#include <string>
using namespace std;
int main() {
	int n;
	cin >> n;
	auto a = new pair<char, int>[n * 5];
	for (int i = 0; i < 5 * n; i++) {
		string s;
		cin >> s;
		a[i] = { s[0], stoi(s.substr(2)) };
	}
	stack<pair<char, int>> s;
	pair<char, int> last = { 0, -1 };
	for (int i = 0; i < n * 5; i++) {
		if (s.empty() || s.top() > a[i]) {
			s.push(a[i]);
		}
		else {
			if (last > s.top()) {
				printf("BAD");
				return 0;
			}
			while (!s.empty() && s.top() < a[i]) {
				last = s.top();
				s.pop();
			}
			s.push(a[i]);
		}
	}
	if (last > s.top()) {
		printf("BAD");
		return 0;
	}
	printf("GOOD");
}