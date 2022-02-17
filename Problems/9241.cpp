#include <iostream>
#include <string>
using namespace std;
int main() {
	string s, t;
	cin >> s >> t;
	int l = 0, r = 0;
	int const sn = s.size();
	int const tn = t.size();
	while (l < sn && s[l] == t[l]) l++;
	while (l + r < sn && l + r < tn && s[sn - 1 - r] == t[tn - 1 - r]) r++;

	printf("%d", tn - l - r);
}