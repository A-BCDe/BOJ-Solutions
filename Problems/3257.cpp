#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main() {
	string s, t, u;
	cin >> s >> t >> u;
	auto a = new bool* [s.size() + 1];
	for (int i = 0; i <= s.size(); i++) {
		a[i] = new bool[t.size() + 1]();
		// a[i][j] : (i : s), (j : t)
		for (int j = 0; j <= t.size(); j++) {
			if (i == 0 && j == 0) a[0][0] = true;
			else if (j > 0 && a[i][j - 1] && t[j - 1] == u[i + j - 1]) {
				a[i][j] = true;
			}
			else if (i > 0 && a[i - 1][j] && s[i - 1] == u[i + j - 1]) {
				a[i][j] = true;
			}
		}
	}

	int i = s.size();
	int j = t.size();
	stack<int> st;
	while (i > 0 || j > 0) {
		if (i > 0 && a[i - 1][j]) {
			st.push(1);
			i--;
		}
		else { // j > 0 && a[i][j - 1]
			st.push(2);
			j--;
		}
	}
	while (!st.empty()) {
		cout << st.top();
		st.pop();
	}
	for (int i = 0; i <= s.size(); i++) {
		delete[] a[i];
	}
	delete[] a;
}