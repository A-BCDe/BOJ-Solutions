#include <iostream>
int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr); std::cout.tie(nullptr);
	int t; std::cin >> t;
	while(t--) {
		long long n;
		std::cin >> n;
		long long p = 5, res = 0;
		while (true) {
			auto const x = n / p;
			if (!x) break;
			res += x;
			p *= 5;
		}
		std::cout << res << '\n';
	}
}