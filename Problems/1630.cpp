#include <stdio.h>
#include <vector>
using namespace std;
int main() {
	long long n;
	long long res = 1;
	scanf("%lld", &n);
	auto a = new bool[n + 1]();
	a[0] = a[1] = true;
	for (int i = 2; i <= n; i++) {
		if (a[i]) continue;
		
		long long mul = i;
		while (mul <= n) mul *= i;
		mul /= i;
		res = (res * mul) % 987654321;

		for (int j = i * 2; j <= n; j += i) {
			a[j] = true;
		}
	}

	printf("%lld", res);

	delete[] a;
}