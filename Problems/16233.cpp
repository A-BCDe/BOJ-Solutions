#include <iostream>
using namespace std;
inline int sum(int n) {
	int res = 0;
	while (n) {
		res += n % 10;
		n /= 10;
	}
	return res;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t; cin >> t;
OK:	while (t--) {
		int n; cin >> n;
		for (int i = (10 - n % 10) % 10; i <= 80; i += 10) {
			int const x = n + i;
			if (sum(x) == i) {
				cout << x << ' ';
				goto OK;
			}
		}
		cout << "-1 ";
	}
}