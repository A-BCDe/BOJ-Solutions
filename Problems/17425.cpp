#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int tt;
	cin >> tt;
	auto f = new long long[1000001]();
	for (int i = 1; i <= 1000000; i++) {
		f[i] += i;
		for (int j = (i << 1); j <= 1000000; j += i) {
			f[j] += i;
		}
	}
	for (int i = 1; i <= 1000000; i++) {
		f[i] += f[i - 1];
	}
	while (tt--) {
		int n;
		cin >> n;
		printf("%lld\n", f[n]);
	}
	delete[] f;
}