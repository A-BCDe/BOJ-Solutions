#include <iostream>
#include <string>
using namespace std;
int main() {
	int tt;
	scanf("%d", &tt);
	for (int ttt = 1; ttt <= tt; ttt++) {
		printf("Data set %d: ", ttt);
		string s, t, u;
		cin >> s >> t >> u;
		auto a = new bool* [s.size() + 1];
		for (int i = 0; i <= s.size(); i++) {
			a[i] = new bool[t.size() + 1]();
			for (int j = 0; j <= t.size(); j++) {
				if (i == 0 && j == 0) {
					a[i][j] = true;
					continue;
				}
				if (i > 0 && a[i - 1][j] && s[i - 1] == u[i + j - 1]) {
					a[i][j] = true;
				}
				if (j > 0 && a[i][j - 1] && t[j - 1] == u[i + j - 1]) {
					a[i][j] = true;
				}
			}
		}
		if (a[s.size()][t.size()]) printf("yes\n");
		else printf("no\n");

		for (int i = 0; i <= s.size(); i++) {
			delete[] a[i];
		}
		delete[] a;
	}
}