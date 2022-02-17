#include <cmath>
#include <iostream>
#include <string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int tt; cin >> tt;
	while (tt--) {
		string s; cin >> s;
		int a[2] = { 0 };
		int idx = 0;
		int mul = 1;
		while (idx < s.size()) {
			int coef = 1;
			int x = 0;
			if (s[idx] == '-') {
				coef = -coef;
				idx++;
				if (s[idx] >= '0' && s[idx] <= '9') {
					coef = 0;
					while (s[idx] >= '0' && s[idx] <= '9') {
						coef *= 10;
						coef -= s[idx++] - '0';
					}
				}
				if (s[idx] == 'x') {
					x = 1;
					idx++;
				}
			}
			else {
				if (s[idx] == '+') idx++;
				if (s[idx] >= '0' && s[idx] <= '9') {
					coef = 0;
					while (s[idx] >= '0' && s[idx] <= '9') {
						coef *= 10;
						coef += s[idx++] - '0';
					}
				}
				if (s[idx] == 'x') {
					x = 1;
					idx++;
				}
			}
			a[x] += mul * coef;
			if (idx < s.size() && s[idx] == '=') {
				idx++;
				mul = -1;
			}
		}
		if (a[0] && !a[1]) {
			printf("IMPOSSIBLE\n");
			continue;
		}
		if (!a[1] && !a[0]) {
			printf("IDENTITY\n");
			continue;
		}
		bool sign = !((a[0] < 0) ^ (a[1] < 0));
		if (!a[0]) sign = false;
		if (a[0] < 0) a[0] = -a[0];
		if (a[1] < 0) a[1] = -a[1];
		int x = a[0] / a[1];
		if (sign) x = -x;
		if (a[0] % a[1] == 0) {
			printf("%d\n", x);
			continue;
		}
		if (sign) x -= 1;
		printf("%d\n", x);
	}
}