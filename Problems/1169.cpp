#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int min(int a, int b) { return a > b ? b : a; }
void dp(vector<int> &v, int *a, int *b, int l, int r, int bl, int br) {
	if (bl >= br || l >= r) return;
	int maxi = l;
	for (int i = l + 1; i < r; i++) {
		if (a[i] > a[maxi]) maxi = i;
	}
	bool left = (bl < b[maxi] - a[maxi]);
	bool right = (br > b[maxi] + a[maxi]);
	if (bl < b[maxi] + a[maxi] && br > b[maxi] - a[maxi]) {
		v.push_back(maxi);
	}
	if (left) {
		int x = min(br, b[maxi] - a[maxi]);
		dp(v, a, b, l, maxi, bl, x);
	}
	if (right) {
		int x = -min(-bl, -b[maxi] - a[maxi]);
		dp(v, a, b, maxi + 1, r, x, br);
	}
}
int main() {
	int n;
	scanf("%d", &n);
	auto a = new int[n];
	auto b = new int[n]();
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		if (i == 0) continue;
		int max = 0;
		for (int j = 0; j < i; j++) {
			int x = 2 * min(a[i], a[j]);
			if (max < x + b[j]) max = x + b[j];
		}
		b[i] = max;
	}
	vector<int> v;
	dp(v, a, b, 0, n, -10000000, 10000000);
	sort(v.begin(), v.end());
	for (auto i : v) {
		printf("%d ", i + 1);
	}
}