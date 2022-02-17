#include <algorithm>
#include <iostream>
using ll = long long;
constexpr ll M = 1000000007;
ll dp(ll* const* const* const* arr, ll a, ll b, ll c, ll s) {
	if (arr[a][b][c][s] != -1) return arr[a][b][c][s];
	if (!s) return arr[a][b][c][0] = (!a && !b && !c);
	if (!a && !b && !c) return arr[a][b][c][s] = !s;
	ll res = 0;
	if(a > 0) res += dp(arr, a - 1, b, c, s - 1);
	if(b > 0) res += dp(arr, a, b - 1, c, s - 1);
	if(c > 0) res += dp(arr, a, b, c - 1, s - 1);
	if(a > 0 && b > 0) res += dp(arr, a - 1, b - 1, c, s - 1);
	if(a > 0 && c > 0) res += dp(arr, a - 1, b, c - 1, s - 1);
	if(b > 0 && c > 0) res += dp(arr, a, b - 1, c - 1, s - 1);
	if(a > 0 && b > 0 && c > 0) res += dp(arr, a - 1, b - 1, c - 1, s - 1);
	res %= M;
	return arr[a][b][c][s] = res;
}
int main() {
	ll s, a, b, c;
	std::cin >> s >> a >> b >> c;
	auto arr = new ll***[a + 1];
	for (int i = 0; i <= a; i++) {
		arr[i] = new ll**[b + 1];
		for (int j = 0; j <= b; j++) {
			arr[i][j] = new ll*[c + 1];
			for (int k = 0; k <= c; k++) {
				arr[i][j][k] = new ll[s + 1];
				std::fill(arr[i][j][k], arr[i][j][k] + s + 1, -1);
			}
		}
	}
	std::cout << dp(arr, a, b, c, s);
}