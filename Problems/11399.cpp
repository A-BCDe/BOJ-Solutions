#include <algorithm>
#include <iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	auto a = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	long long sum = 0;
	for (int i = 0; i < n; i++) {
		sum += a[i] * (n - i);
	}
	cout << sum;
}