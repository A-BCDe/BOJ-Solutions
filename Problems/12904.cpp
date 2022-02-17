#include <iostream>
#include <string>
using namespace std;
int main() {
	string s, t;
	cin >> s >> t;
	auto const sl = s.size();
	for (auto tl = t.size(); sl < tl; tl--) {
		if (t[tl - 1] == 'A') {
			t.resize(tl - 1);
		}
		else if (t[tl - 1] == 'B') {
			t.resize(tl - 1);
			for (int i = 0; i < (tl - 1) / 2; i++) {
				auto tmp = t[i];
				t[i] = t[tl - i - 2];
				t[tl - i - 2] = tmp;
			}
		}
		else {
			printf("0");
			return 0;
		}
	}
	printf(t == s ? "1" : "0");
}