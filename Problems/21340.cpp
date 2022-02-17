#include <iostream>
using namespace std;
using ll = long long;
struct str {
	void operator()(int& first, int& second) {
		first = x; second = y;

	}
	str() : x(500000), y(500000) {}
	void reset() {
		x = 500000;
		y = 500000;

	}

	int x, y;
};
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin >> n;
	str get_next;
	for (int i = 0; i < 1000; i++) {
		int x, y;
		get_next(x, y);
		cout << x << ' ' << y << '\n';
		cout.flush();
		ll res;
		cin >> res;
		if (!res) get_next.reset();
	}
}