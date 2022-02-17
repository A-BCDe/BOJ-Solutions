#include <iostream>
#include <set>
#include <string>
using namespace std;
int strike(char cstr[5], char str[4]) {
	int res = 0;
	for (int i = 0; i < 4; i++) {
		res += (cstr[i] == str[i]);
	}
	return res;
}
int ball(char cstr[5], char str[4]) {
	int res = 0;
	int b[4];
	for (int i = 0; i < 4; i++) {
		b[i] = (cstr[i] == str[i]);
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (i == j || b[j]) continue;
			if (cstr[i] == str[j]) {
				res++; b[j] = 1;
				break;
			}
		}
	}
	return res;
}
void compare(int a[26][26][26][26], char cstr[5], int l, int r) {
	for (int w = 0; w < 26; w++) {
		for (int x = 0; x < 26; x++) {
			for (int y = 0; y < 26; y++) {
				for (int z = 0; z < 26; z++) {
					char str[4] = { w + 'a', x + 'a', y + 'a', z + 'a' };
					if (a[w][x][y][z] || strike(cstr, str) != l || ball(cstr, str) != r) a[w][x][y][z] = 1;
				}
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int a[26][26][26][26] = {};
	int cnt = 0;
	for (int w = 0; w < 26; w++) {
		for (int x = 0; x < 26; x++) {
			for (int y = 0; y < 26; y++) {
				for (int z = 0; z < 26; z++) {
					if (!a[w][x][y][z]) {
						char cstr[5] = { w + 'a', x + 'a', y + 'a', z + 'a', '\0' };
						cout << cstr << '\n';
						cout.flush();
						cnt++;
						if (cnt == 50) return 0;
						string s;
						cin >> s;
						if (s == "correct") return 0;
						int l = s[0] - '0';
						cin >> s;
						int r = s[0] - '0';
						compare(a, cstr, l, r);
					}
				}
			}
		}
	}
}