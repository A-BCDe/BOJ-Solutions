#include <algorithm>
#include <stdio.h>
#include <string>
#include <vector>
long long phi(long long n) {
	auto res = n;
	for (long long i = 2; i * i <= n; i++) {
		bool flag = false;
		while (n % i == 0) {
			flag = true;
			n /= i;
		}
		if (!flag) continue;
		res /= i;
		res *= i - 1;
	}
	if (n > 1) {
		res /= n;
		res *= n - 1;
	}
	return res;
}
int main() {
	int n; scanf("%d", &n);
	std::vector<int> v;
	for (int i = 1; i * i <= n; i++) {
		if (n % i == 0) {
			v.push_back(i);
			if (i * i != n) v.push_back(n / i);
		}
	}
	std::sort(v.begin(), v.end());
	for (auto x : v) {
		if (x * phi(x) == n) {
			printf("%d", x);
			return 0;
		}
	}
	printf("-1");
}