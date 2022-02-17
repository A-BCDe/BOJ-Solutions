#include <stdio.h>
#include <algorithm>
int main() {
	int n;
	scanf("%d", &n);
	auto a = new int[n];
	auto b = new int[n];
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &a[i], &b[i]);
	}
	std::sort(a, a + n);
	std::sort(b, b + n);
	int ai = 0, bi = 0;
	int cur = 0;
	int max = 0;
	while (ai < n) {
		if (a[ai] > b[bi]) {
			int x = bi;
			while (bi < n && b[bi] == b[x]) bi++;
			cur -= bi - x;
			continue;
		}
		if (a[ai] < b[bi]) {
			int x = ai;
			while (ai < n && a[ai] == a[x]) ai++;
			cur += ai - x;
			if (max < cur) max = cur;
			continue;
		}
		int x = ai, y = bi;
		while (ai < n && a[ai] == a[x]) ai++;
		while (bi < n && b[bi] == b[y]) bi++;
		cur += ai - x + y - bi;
		if (max < cur) max = cur;
	}
	printf("%d", max);
	delete[] a;
	delete[] b;
}