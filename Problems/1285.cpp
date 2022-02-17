#include <iostream>
#include <string>
using namespace std;
inline void flip(string& s) {
	for (auto& c : s) c = ((c == 'T') ? 'H' : 'T');
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n; cin >> n;
	auto a = new string[n];
	int res = n * n;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < (1 << n); i++) {
		auto arr = new string[n];
		for (int j = 0; j < n; j++) {
			arr[j] = a[j];
			if (i & (1 << j)) flip(arr[j]);
		}
		int r = 0;
		for (int j = 0; j < n; j++) {
			int cnt = 0;
			for (int k = 0; k < n; k++) {
				cnt += (arr[k][j] == 'T');
			}
			r += cnt;
			if ((cnt << 1) > n) {
				r -= (cnt << 1) - n;
			}
		}
		if (res > r) res = r;
		delete[] arr;
	}
	cout << res;
}