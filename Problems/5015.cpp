#include <iostream>
#include <algorithm>
using namespace std;
bool match(string const& s, string const& t, int** arr, size_t sidx, size_t tidx) {
	if (arr[sidx][tidx] != -1) return arr[sidx][tidx];
	if (tidx == t.size()) {
		if (sidx == s.size()) return arr[sidx][tidx] = 1;
		if (s[sidx] == '*') return arr[sidx][tidx] = match(s, t, arr, sidx + 1, tidx);
		return false;
	}
	if (sidx == s.size()) return arr[sidx][tidx] = (tidx == t.size());
	if (s[sidx] == t[tidx]) return arr[sidx][tidx] = match(s, t, arr, sidx + 1, tidx + 1);
	if (s[sidx] == '*') return arr[sidx][tidx] = (match(s, t, arr, sidx + 1, tidx) || match(s, t, arr, sidx, tidx + 1));
	return arr[sidx][tidx] = 0;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	string s; cin >> s;
	int n; cin >> n;
	while (n--) {
		string t; cin >> t;
		auto arr = new int* [s.size() + 1];
		for (int i = 0; i <= s.size(); i++) {
			arr[i] = new int[t.size() + 1];
			fill(arr[i], arr[i] + t.size() + 1, -1);
		}
		if (match(s, t, arr, 0, 0)) cout << t << '\n';
		for (int i = 0; i <= s.size(); i++) delete[] arr[i];
		delete[] arr;
	}
}