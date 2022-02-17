#include <algorithm>
#include <stdio.h>
#include <string>
#include <utility>
using namespace std;
bool comp(string a, string b) {
	if (a.size() < b.size()) return true;
	if (a.size() > b.size()) return false;
	for (int i = a.size() - 1; i >= 0; i--) {
		if (a[i] < b[i]) return true;
		if (a[i] > b[i]) return false;
	}
	return false;
}
// ...d, 0...0 (d > 0)
pair<string, string> dp(int const* a, pair<string, string>*** arr, int digit, int cash) {
	if (arr[digit][cash]) return *arr[digit][cash];
	if (!cash) return *(arr[digit][0] = new pair<string, string>("", ""));
	pair<string, string> res;
	if (a[digit] <= cash) {
		res = dp(a, arr, digit, cash - a[digit]);
		res.first += digit + '0';
		res.second += digit + '0';
		if (!digit) {
			if (comp(res.second, res.first)) {
				res.second = move(res.first);
			}
			res.first = "";
		}
		else {
			if (comp(res.first, res.second)) {
				res.first = move(res.second);
			}
			res.second = "";
		}
	}
	if (cash && digit) {
		auto s = dp(a, arr, digit - 1, cash);
		if (comp(res.first, s.first)) res.first = s.first;
		if (comp(res.second, s.second)) res.second = s.second;
	}
	arr[digit][cash] = new pair<string, string>(res);
	return res;
}
int main() {
	int n, m;
	scanf("%d", &n);
	auto a = new int[n];
	auto arr = new pair<string, string>**[n];
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	scanf("%d", &m);
	for (int i = 0; i < n; i++) {
		arr[i] = new pair<string, string>*[m + 1]();
	}
	auto p = dp(a, arr, n - 1, m);
	while (p.first.size() > 1 && p.first.back() == '0') p.first.pop_back();
	while (p.second.size() > 1 && p.second.back() == '0') p.second.pop_back();
	string s;
	if (comp(p.first, p.second)) s = p.second;
	else s = p.first;
	reverse(s.begin(), s.end());
	printf("%s", s.c_str());
	delete[] a;
}