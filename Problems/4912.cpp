#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	char c;
	string s;
	vector<string> v;
	while (getline(cin, s)) {
		if (s.size() >= 80) return 0;
		v.push_back(s);
	}
	for (int i = 0; i < v.size(); i++) {
		string& s = v[i];
		int idx = 0;
		while (idx < s.size()) {
			if (idx < s.size() - 2 && s[idx] == 'E' && s[idx + 1] == 'O' && s[idx + 2] == 'F') return 0;
			if (!(s[idx] >= 'a' && s[idx] <= 'z') && (s[idx] > ' ' && s[idx] != 127)) { idx++; continue; }
			if (idx < s.size() - 1 && s[idx] == 'd' && s[idx + 1] == 'd') {
				printf("p");
				idx += 2;
				continue;
			}
			if (idx < s.size() - 3 && s[idx] == 'p' && s[idx + 1] == 'i' && s[idx + 2] == 'n' && s[idx + 3] == 'k') {
				printf("floyd");
				idx += 4;
				continue;
			}
			if (idx < s.size() - 2 && s[idx] != 'c' && s[idx + 1] == 'e' && s[idx + 2] == 'i') {
				s[idx + 1] = 'i';
				s[idx + 2] = 'e';
			}
			printf("%c", s[idx]);
			idx++;
		}
		if(i < v.size() - 1) printf("\n");
	}
}