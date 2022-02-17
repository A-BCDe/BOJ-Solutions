#include <iostream>
#include <string>
using namespace std;
bool f(int a[12], bool b[13], int idx) {
	if (idx == 12) {
		int res[6];
		res[0] = a[1] + a[2] + a[3] + a[4];
		res[1] = a[0] + a[2] + a[5] + a[7];
		res[2] = a[0] + a[3] + a[6] + a[10];
		res[3] = a[1] + a[5] + a[8] + a[11];
		res[4] = a[4] + a[6] + a[9] + a[11];
		res[5] = a[7] + a[8] + a[9] + a[10];
		int r = res[0];
		for (int i = 1; i < 6; i++) {
			if (r != res[i]) return false;
		}
		return true;
	}
	if (a[idx]) return f(a, b, idx + 1);
	for (int i = 1; i < 13; i++) {
		if (b[i]) continue;
		b[i] = true;
		a[idx] = i;
		if (f(a, b, idx + 1)) return true;
		a[idx] = 0;
		b[i] = false;
	}
	return false;
}
int main() {
	string s[5];
	cin >> s[0] >> s[1] >> s[2] >> s[3] >> s[4];
	int a[12] = {};
	a[0] = (s[0][4] == 'x' ? 0 : (s[0][4] - 'A' + 1));
	a[1] = (s[1][1] == 'x' ? 0 : (s[1][1] - 'A' + 1));
	a[2] = (s[1][3] == 'x' ? 0 : (s[1][3] - 'A' + 1));
	a[3] = (s[1][5] == 'x' ? 0 : (s[1][5] - 'A' + 1));
	a[4] = (s[1][7] == 'x' ? 0 : (s[1][7] - 'A' + 1));
	a[5] = (s[2][2] == 'x' ? 0 : (s[2][2] - 'A' + 1));
	a[6] = (s[2][6] == 'x' ? 0 : (s[2][6] - 'A' + 1));
	a[7] = (s[3][1] == 'x' ? 0 : (s[3][1] - 'A' + 1));
	a[8] = (s[3][3] == 'x' ? 0 : (s[3][3] - 'A' + 1));
	a[9] = (s[3][5] == 'x' ? 0 : (s[3][5] - 'A' + 1));
	a[10] = (s[3][7] == 'x' ? 0 : (s[3][7] - 'A' + 1));
	a[11] = (s[4][4] == 'x' ? 0 : (s[4][4] - 'A' + 1));
	bool b[13] = {};
	for (int i = 0; i < 12; i++) {
		b[a[i]] = true;
	}
	if (f(a, b, 0)) {
		printf("....%c....\n", (char)(a[0] + 'A' - 1));
		printf(".%c.%c.%c.%c.\n", (char)(a[1] + 'A' - 1), (char)(a[2] + 'A' - 1), (char)(a[3] + 'A' - 1), (char)(a[4] + 'A' - 1));
		printf("..%c...%c..\n", (char)(a[5] + 'A' - 1), (char)(a[6] + 'A' - 1));
		printf(".%c.%c.%c.%c.\n", (char)(a[7] + 'A' - 1), (char)(a[8] + 'A' - 1), (char)(a[9] + 'A' - 1), (char)(a[10] + 'A' - 1));
		printf("....%c....\n", (char)(a[11] + 'A' - 1));
	}
}