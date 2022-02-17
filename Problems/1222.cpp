#include <stdio.h>
using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	auto a = new int[2000001]();
	int max = 0;
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		if (max < x) max = x;
		a[x]++;
	}
	long long res = 0;
	for (int i = 1; i <= max; i++) {
		long long sum = 0;
		for (int j = i; j <= max; j += i) {
			sum += a[j];
		}
		if (sum == 1) continue;
		if (res < sum * i) res = sum * i;
	}
	printf("%lld", res);
	delete[] a;
}