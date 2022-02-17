#include <iostream>
#include <string>
using namespace std;
int main() {
	string s;
	getline(cin, s);
	string const t = "UCPC";
	int idx = 0, cur = 0;
	while (idx < s.size() && cur < 4) {
		cur += (s[idx] == t[cur]);
		idx++;
	}
	if (cur == 4) printf("I love UCPC");
	else printf("I hate UCPC");
}	