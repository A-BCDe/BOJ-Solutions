#include <stdio.h>
int abs(int x) { return x > 0 ? x : -x; }
int main() {
	int n, l, p;
	scanf("%d%d%d", &n, &l, &p);
	auto a = new int[n];
	int d = l / 2;
	for (int i = 0; i < n; i++) {
		a[i] = d;
		d += l;
	}
	auto b = new int[n]();
	int max = 0;
	for (int i = 0; i < p; i++) {
		int x;
		scanf("%d", &x);
		int min = 1000000;
		int minj = 0;
		for (int j = 0; j < n; j++) {
			if (min >= abs(a[j] - x)) {
				min = abs(a[j] - x);
				minj = j;
			}
		}
		b[minj]++;
		if (max < min) max = min;
	}
	printf("%d\n", max);
	int res = 0;
	for (int i = 1; i < n; i++) {
		if (b[i] > b[res]) res = i;
	}
	printf("%d", b[res]);
	delete[] a;
}