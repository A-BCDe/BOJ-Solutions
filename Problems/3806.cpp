#include <iostream>
#include <string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int xx; cin >> xx;
	for(int tc = 1; tc <= xx; tc++) {
		printf("Case %d: ", tc);
		string s, t;
		cin >> s >> t;
		int ss[3] = {}, tt[2] = {};
		for (auto c : s) {
			if (c == '0') ss[0]++;
			else if (c == '1') ss[1]++;
			else ss[2]++;
		}
		for (auto c : t) {
			if (c == '0') tt[0]++;
			else tt[1]++;
		}
		if (ss[0] + ss[2] < tt[0]) {
			printf("-1\n");
			continue;
		}
		int cnt = ss[2];
		for (int i = 0; i < s.size(); i++) {
			if (ss[0] <= tt[0]) break;
			if (s[i] == '0' && t[i] == '1') {
				s[i] = '1';
				ss[0]--; ss[1]++;
				cnt++;
			}
		}
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '?') {
				if (t[i] == '0' && ss[0] < tt[0]) {
					s[i] = '0';
					ss[0]++; ss[2]--;
				}
			}
		}
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '?') {
				if (ss[0] < tt[0]) {
					s[i] = '0';
					ss[0]++; ss[2]--;
				}
				else {
					s[i] = '1';
					ss[1]++; ss[2]--;
				}
			}
		}
		/*printf("ss: ");
		for (int i = 0; i < 3; i++) {
			printf("%d ", ss[i]);
		} printf("\ntt: ");
		for (int i = 0; i < 2; i++) {
			printf("%d ", tt[i]);
		} printf("\n");*/
		int x = 0;
		for (int i = 0; i < s.size(); i++) {
			x += (s[i] != t[i]);
		}
		printf("%d\n", cnt + x / 2);
	}
}