#include <stdio.h>
#include <algorithm>
int main() {
	long long n, m;
	scanf("%lld%lld", &n, &m);
	auto a = new long long[n];
	for (int i = 0; i < n; i++) {
		scanf("%lld", &a[i]);
	}
	std::sort(a, a + n);
	long long min = 2000000001;
	for (int i = 0, j = 1; j < n;) {
		if (i == j) j++;
		if (a[j] - a[i] >= m) {
			if (min > a[j] - a[i]) min = a[j] - a[i];
			i++;
		}
		else j++;
	}
	printf("%lld", min);
	delete[] a;
}