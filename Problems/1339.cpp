#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
using ll = long long;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n; cin >> n;
	ll a[26] = { 0 };
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		ll mul = 1;
		for (ll j = s.size() - 1; j >= 0; j--) {
			a[s[j] - 'A'] += mul;
			mul *= 10;
		}
	}
	sort(a, a + 26);
	ll res = 0;
	for (int i = 16; i < 26; i++) {
		res += a[i] * (i - 16);
	}
	cout << res;
}