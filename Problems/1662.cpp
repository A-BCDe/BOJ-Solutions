#include <iostream>
#include <string>
using namespace std;
int main() {
	string s;
	cin >> s;
	int idx = 0;
	int len = 0;

	while (idx < s.size()) {
		if (!(idx && s[idx] == '(')) {
			idx++;
			len++;
			continue;
		}
		int const start = idx++;
		if(s[start - 1] < '0' || s[start - 1] > '9') {
			len++;
			continue;
		}
		while (idx < s.size() && s[idx] >= '0' && s[idx] <= '9') {
			idx++;
		}
		if (idx == s.size()) {
			len += idx - start;
			break;
		}
		if (s[idx] != ')') {
			len += idx - start;
			continue;
		}
		int x = 0;
		for (int i = start + 1; i < idx; i++) {
			x *= 10;
			x += s[i] - '0';
		}
		len += x - 1;
		idx++;
	}
	printf("%d", len);
}