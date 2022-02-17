#include <array>
#include <iostream>
using namespace std;
inline int hi(int n) {
	int res = 1;
	while (n >= 10) {
		res *= 10;
		n /= 10;
	}
	return res;
}
inline void add(array<int, 10>& arr, array<int, 10> const& adder) {
	for (int i = 0; i < 10; i++) arr[i] += adder[i];
}
array<int, 10> zero(int n, int k) {
	if (k == 1) {
		array<int, 10> res;
		int i = 0;
		for (; i <= n; i++) res[i] = 1;
		for (; i < 10; i++) res[i] = 0;
		return res;
	}
	auto const zarr = zero(k - 1, k / 10);
	array<int, 10> res{};
	for (int i = 0; i <= n; i += k) {
		if (i + k <= n) {
			res[i / k] += k;
			add(res, zarr);
		}
		else {
			res[i / k] += n - i + 1;
			add(res, zero(n - i, k / 10));
		}
	}
	return res;
}
array<int, 10> nonzero(int n, int k) {
	if (k == 1) {
		array<int, 10> res;
		int i = 1;
		res[0] = 0;
		for (; i <= n; i++) res[i] = 1;
		for (; i < 10; i++) res[i] = 0;
		return res;
	}
	if (n < k) return nonzero(n, k / 10);
	auto const zarr = zero(k - 1, k / 10);
	auto res = nonzero(k - 1, k / 10);
	for (int i = k; i <= n; i += k) {
		if (i + k <= n) {
			res[i / k] += k;
			add(res, zarr);
		}
		else {
			res[i / k] += n - i + 1;
			add(res, zero(n - i, k / 10));
		}
	}
	return res;
}
int main() {
	int n, k;
	cin >> n;
	k = hi(n);
	auto arr = nonzero(n, k);
	for (int i = 0; i < 10; i++) {
		cout << arr[i] << ' ';
	}
}