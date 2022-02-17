#include <iostream>
#include <cinttypes>
using namespace std;
int main() {
	long double va = 0;
	long double vb = -1;
	long double ma = 1;
	int n;
	scanf("%d", &n);
	long double mb = n * n;
	long double C1 = (ma - mb) / (ma + mb);
	long double C2 = 2 * mb / (ma + mb);
	long double C3 = 2 * ma / (ma + mb);
	int cnt = 0;
	while (true) {
		if (va <= vb) break;
		cnt++;
		long double ua, ub;
		ua = C1 * va + C2 * vb;
		ub = C3 * va - C1 * vb;
		if (ua >= 0) break;
		va = -ua;
		cnt++;
		vb = ub;
	}
	printf("%d", cnt);
}