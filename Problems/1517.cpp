#include <algorithm>
#include <iostream>
using namespace std;
using ll = long long;
ll f(int* a, int n, int l, int r) {
	if (l + 1 >= r) return 0;
	auto const m = (l + r) / 2;
	ll res = f(a, n, l, m) + f(a, n, m, r);
	auto left = l, right = m;
	auto arr = new int[r - l];
	int idx = 0;
	while (left < m || right < r) {
		if (left == m) {
			arr[idx] = a[right];
			idx++; right++;
			continue;
		}
		if (right == r) {
			arr[idx] = a[left];
			res += r - m;
			idx++; left++;
			continue;
		}
		if (a[left] <= a[right]) {
			arr[idx] = a[left];
			res += right - m;
			idx++; left++;
			continue;
		}
		arr[idx] = a[right];
		idx++; right++;
	}
	copy(arr, arr + r - l, a + l);
	delete[] arr;
	return res;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n; cin >> n;
	auto a = new int[n];
	for (int i = 0; i < n; i++) cin >> a[i];
	cout << f(a, n, 0, n);
}