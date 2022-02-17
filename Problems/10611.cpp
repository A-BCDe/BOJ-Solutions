#include <stdio.h>
#include <algorithm>
using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	auto a = new int[n];
	int max = 0;
	int min = 1000000;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		if (max < a[i]) max = a[i];
		if (min > a[i]) min = a[i];
	}
	sort(a, a + n);
	auto d = new int[max + 1]();
	for (int i = 0; i < n; i++) {
		d[a[i]]++;
	}
	int l = min, r = max;
	int lidx = lower_bound(a, a + n, l) - a;
	int ridx = lower_bound(a, a + n, r) - a;
	bool turn = false;
	while (lower_bound(a, a + n, l + 1) - a < ridx) {
		int dmin = d[l];
		if (dmin > d[r]) dmin = d[r];
		if (turn) {
			if (dmin == d[r]) {
				d[l] -= dmin - 1;
				d[r] = 0;
				turn = false;
				r = a[ridx = lower_bound(a, a + n, *(lower_bound(a, a + n, r) - 1)) - a];
				d[r] += dmin;
				d[*lower_bound(a, a + n, l + 1)] += dmin - 1;
			}
			else {
				d[l] = 0;
				d[r] -= dmin;
				l = a[lidx = lower_bound(a, a + n, l + 1) - a];
				d[l] += dmin;
				d[*(lower_bound(a, a + n, r) - 1)] += dmin;
			}
		}
		else {
			if (dmin == d[l]) {
				d[l] = 0;
				d[r] -= dmin - 1;
				turn = true;
				l = a[lidx = lower_bound(a, a + n, l + 1) - a];
				d[l] += dmin;
				d[*(lower_bound(a, a + n, r) - 1)] += dmin - 1;
			}
			else {
				d[l] -= dmin;
				d[r] = 0;
				r = a[ridx = lower_bound(a, a + n, *(lower_bound(a, a + n, r) - 1)) - a];
				d[r] += dmin;
				d[*lower_bound(a, a + n, l + 1)] += dmin;
			}
		}
	}
	if (!turn) {
		printf("Slavko\n%d %d", l, r);
	}
	else printf("Mirko\n%d %d", l, r);
}