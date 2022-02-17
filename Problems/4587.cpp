#include <stdio.h>
#include <vector>
using namespace std;
long long gcd(long long a, long long b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}
long long lcm(long long a, long long b) {
	return a / gcd(a, b) * b;
}
int main() {
	while (true) {
		long long a, b;
		scanf("%lld%lld", &a, &b);
		if (a == 0 && b == 0) return 0;
		vector<long long> v;
		long long d = 2;
		while (a != 0) {
			while (a * d < b) d++;
			long long l = lcm(b, d);
			long long a_prev = a, b_prev = b;
			a *= l / b;
			a -= l / d;
			b = l;
			long long g = gcd(a, b);
			a /= g; b /= g;
			if (b >= 1000000) {
				a = a_prev;
				b = b_prev;
				d++;
			}
			else v.push_back(d);
		}
		for (auto now : v) {
			printf("%lld ", now);
		}
		printf("\n");
	}
}