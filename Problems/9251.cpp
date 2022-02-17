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
	for(int i = 0; i < s.size(); i++) {
		for(int j = 0; j < t.size(); j++) {
			a[i + 1][j + 1] = a[i][j] + (s[i] == t[j]);
			if(a[i][j + 1] > a[i + 1][j + 1]) a[i + 1][j + 1] = a[i][j + 1];
			if(a[i + 1][j] > a[i + 1][j + 1]) a[i + 1][j + 1] = a[i + 1][j];
		}
	}
	cout << a[s.size()][t.size()];
}