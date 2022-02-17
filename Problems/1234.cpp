#include <iostream>
using ll = unsigned long long;
ll dp(ll* const* const* arr, bool* const* const* visited, ll n, ll r, ll g, ll b) {
	if (visited[r][g][b]) return arr[r][g][b];
	if (!n) return arr[r][g][b] = 1;
	ll res = 0;
	if (r >= n) res = dp(arr, visited, n - 1, r - n, g, b);
	if (g >= n) res += dp(arr, visited, n - 1, r, g - n, b);
	if (b >= n) res += dp(arr, visited, n - 1, r, g, b - n);
	if (n % 2 == 0) {
		ll mul = 1;
		for (ll i = 1; i <= n / 2; i++) mul = mul * (n - i + 1) / i;
		bool const x = (r >= n / 2), y = (g >= n / 2), z = (b >= n / 2);
		if (x && y) res += dp(arr, visited, n - 1, r - n / 2, g - n / 2, b) * mul;
		if (x && z) res += dp(arr, visited, n - 1, r - n / 2, g, b - n / 2) * mul;
		if (y && z) res += dp(arr, visited, n - 1, r, g - n / 2, b - n / 2) * mul;
	}
	if (n % 3 == 0 && r >= n / 3 && g >= n / 3 && b >= n / 3) {
		ll mul = 1;
		for (ll i = 1; i <= n / 3; i++) mul = mul * (n - i + 1) / i;
		for (ll i = 1; i <= n / 3; i++) mul = mul * (n * 2 / 3 - i + 1) / i;
		res += dp(arr, visited, n - 1, r - n / 3, g - n / 3, b - n / 3) * mul;
	}
	visited[r][g][b] = true;
	return arr[r][g][b] = res;
}
int main() {
	ll n, r, g, b;
	std::cin >> n >> r >> g >> b;
	auto arr = new ll**[r + 1];
	auto visited = new bool**[r + 1];
	for (int i = 0; i <= r; i++) {
		arr[i] = new ll*[g + 1];
		visited[i] = new bool*[g + 1];
		for (int j = 0; j <= g; j++) {
			arr[i][j] = new ll[b + 1];
			visited[i][j] = new bool[b + 1]();
		}
	}
	std::cout << dp(arr, visited, n, r, g, b);
}