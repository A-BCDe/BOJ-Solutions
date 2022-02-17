#include <stdio.h>
void insert(int* t, int tidx, int taste, int cnt, int l, int r) {
	t[tidx] += cnt;
	if (l == r) return;
	auto const m = (l + r) / 2;
	if (taste <= m) insert(t, tidx * 2, taste, cnt, l, m);
	else insert(t, tidx * 2 + 1, taste, cnt, m + 1, r);
}
int kth(int* t, int tidx, int k, int l, int r) {
	t[tidx]--;
	if (l == r) return l;
	auto const m = (l + r) / 2;
	if (k <= t[tidx * 2]) return kth(t, tidx * 2, k, l, m);
	else return kth(t, tidx * 2 + 1, k - t[tidx * 2], m + 1, r);
}
int main() {
	int n;
	scanf("%d", &n);
	auto t = new int[4000000]();
	while (n--) {
		int a, b;
		scanf("%d%d", &a, &b);
		if (a == 1) {
			printf("%d\n", kth(t, 1, b, 1, 1000000));
		}
		else {
			scanf("%d", &a);
			insert(t, 1, b, a, 1, 1000000);
		}
	}
}