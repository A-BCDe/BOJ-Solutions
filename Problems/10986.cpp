#include <algorithm>
#include <iostream>
int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	int n, m; std::cin >> n >> m;
	auto a = new int[n + 1];
	a[0] = 0;
	auto arr = new long long[m]();
	arr[0] = 1;
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
		a[i] += a[i - 1];
		a[i] %= m;
		arr[a[i]]++;
	}
	long long res = 0;
	for (int i = 0; i < m; i++) {
		res += ((arr[i] * (arr[i] - 1)) >> 1);
	}
	std::cout << res;
	delete[] a;
}