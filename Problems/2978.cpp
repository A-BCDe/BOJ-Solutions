#include <cstdlib>
#include <iostream>
#include <string>
#include <utility>
using namespace std;
// next off - cur off, # +
pair<int, int> f(pair<int, int> *const dp, int const SSIZE, string const &A, int const off, int const S) {
	if(dp[off * SSIZE + S].second != -2) return dp[off * SSIZE + S];
	if(off == A.size() && !S) return dp[off * SSIZE + S] = { 0, 0 };
	int x = A[off] - '0';
	for(int i = 1; off + i <= A.size() && x <= S; i++) {
		auto const p = f(dp, SSIZE, A, off + i, S - x);
		if(p.second != -1 && (dp[off * SSIZE + S].second == -2 || dp[off * SSIZE + S].second > p.second + 1)) {
			dp[off * SSIZE + S] = { i, p.second + 1 };
		}
		x = x * 10 + A[off + i] - '0';
	}
	if(dp[off * SSIZE + S].second == -2) dp[off * SSIZE + S].second = -1;
	return dp[off * SSIZE + S];
}
inline int string_to_int(string const &s) {
	int x = 0;
	for(char c : s) {
		x = x * 10 + c - '0';
	} return x;
}
void print(pair<int, int> *const dp, int const SSIZE, string const &A, int const off, int const S) {
	int x = 0;
	for(int i = off; i < off + dp[off * SSIZE + S].first; i++) {
		cout << A[i];
		x = x * 10 + A[i] - '0';
	}
	if(dp[off * SSIZE + S].second == 1) return;
	cout << '+';
	print(dp, SSIZE, A, off + dp[off * SSIZE + S].first, S - x);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	string s; cin >> s;
	string A; int S;
	for(int i = 0; i < s.size(); i++) {
		if(s[i] == '=') {
			A = s.substr(0, i);
			S = string_to_int(s.substr(i + 1));
			break;
		}
	}
	auto const dp = (pair<int, int>*)malloc(sizeof(pair<int, int>*) * (A.size() + 1) * (S + 1));
	for(int i = 0; i < (A.size() + 1) * (S + 1); i++) dp[i].second = -2;
	f(dp, S + 1, A, 0, S);
	/*
	for(int i = 0; i <= A.size(); i++) {
		for(int j = 0; j <= S; j++) {
			cout << '(' << dp[i][j].first << ", " << dp[i][j].second << ") ";
		} cout << '\n';
	} cout << '\n';
	 */
	print(dp, S + 1, A, 0, S);
	cout << '=' << S;
}