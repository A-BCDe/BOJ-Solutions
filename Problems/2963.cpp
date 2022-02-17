#include <iostream>
#include <stack>
#include <string>
using namespace std;
string pow5 = "1";
string seqb = "1";
string add(string const& s1, string const& s2) {
	string s;
	int i, c = 0;
	for (i = 0; i < s1.size() && i < s2.size(); i++) {
		int next = (s1[i] - '0') + (s2[i] - '0') + c;
		c = next / 10;
		s.push_back(next % 10 + '0');
	}
	while (i < s1.size()) {
		int next = (s1[i++] - '0') + c;
		c = next / 10;
		s.push_back(next % 10 + '0');
	}
	while (i < s2.size()) {
		int next = (s2[i++] - '0') + c;
		c = next / 10;
		s.push_back(next % 10 + '0');
	}
	if (c) s.push_back('1');
	return s;
}
string sub(string const& s1, string const& s2) {
	string s;
	
}
string L(string const& s) {
	return add(s, s);
}
string R(string const& s) {
	return add(add(s, s), "1");
}
string star(string const& s) {
	string s1 = add(s, s);
	string s2 = add(s1, s1);
	string s3 = add(s2, s);
	string s4 = add(s3, seqb);
	seqb = add(add(seqb, seqb), seqb);
	seqb = add(seqb, pow5);
	string s5 = add(pow5, pow5);
	pow5 = add(add(s5, s5), pow5);
	return s4;
}
int main() {
	string s;
	cin >> s;
	string res = "1";
	for (char c : s) {
		switch (c) {
		case 'L': res = L(res); break;
		case 'R': res = R(res); break;
		case 'P': break;
		case '*': res = star(res); break;
		}
	}
	for (int i = res.size() - 1; i >= 0; i--) {
		printf("%c", res[i]);
	}
}