#include <iostream>
double max(int* s, int n, int a0) {
	double d = s[1] + 1 - a0;
	for (int i = 2; i <= n; i++) {
		double const x = (s[i] + 1 - a0) / (double)i;
		if (d > x) d = x;
	}
	return d;
}
double min(int* s, int n, int a0) {
	double d = s[1] - a0;
	for (int i = 2; i <= n; i++) {
		double const x = (s[i] - a0) / (double)i;
		if (d < x) d = x;
	}
	return d;
}

int main() {
	int n, a0;
	scanf("%d%d", &n, &a0);
	if (n == 0) {
		printf("0");
		return 0;
	}
	auto s = new int[n + 1];
	s[0] = a0;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &s[i]);
		if (s[i] < s[0]) {
			printf("-1");
			delete[] s;
			return 0;
		}
	}

	double l = min(s, n, a0), r = max(s, n, a0);
	std::cout.precision(9);
	if (l > r) {
		printf("-1");
		delete[] s;
		return 0;
	}
	if (l < 0) {
		printf("-1");
		delete[] s;
		return 0;
	}
	std::cout << l;
	delete[] s;
}