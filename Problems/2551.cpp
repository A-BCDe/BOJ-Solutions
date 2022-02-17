#include <algorithm>
#include <iostream>
using namespace std;
long long f(long long sum, long long n) {
	auto const m = sum / n;
	if ((m + 1) * n - sum >= sum - m * n) return m;
	return m + 1;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n; cin >> n;
	auto a = new int[n];
	long long sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	sort(a, a + n);
	cout << a[(n - 1) / 2] << ' ' << f(sum, n);
	delete[] a;
}