#include <stdio.h>
#include <algorithm>
#include <utility>
using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	auto a = new pair<int, bool>[2 * n];
	for (int i = 0; i < n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		a[2 * i] = make_pair(x, false);
		a[2 * i + 1] = make_pair(y, true);
	}
	std::sort(a, a + 2 * n);

	int res = 0;
	int prev = a[0].first;
	int pivot = 0;
	int i = 0;
	while (i < 2 * n) {
		int cur = a[i].first;
		while (i < 2 * n && a[i].first == cur) {
			if (a[i].second) pivot++;
			else pivot--;
			i++;
		}
		if (pivot == 0) {
			res += cur - prev;
			prev = a[i].first;
		}
	}
	printf("%d", res);
}