#include <cassert>
#include <iostream>
using namespace std;
using ll = long long;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin >> n;
	ll x, min = 10000000000;
	for (int i = 0; i < n; i++) {
		cin >> x;
		assert(x <= 1000000000);
		assert(x >= -1000000000);
		if (min > x) min = x;
	}
	cout << min << ".00";
}