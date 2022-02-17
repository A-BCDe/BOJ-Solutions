#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, k;
	cin >> n >> k;
	auto a = new int[n]();
	auto arr = new int*[n];
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if ((k << 1) > n) {
		cout << 0;
		return 0;
	}

}