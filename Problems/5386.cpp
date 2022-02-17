#include <stdio.h>
int main() {
	int tt;
	scanf("%d", &tt);
	while (tt--) {
		/*
		int s, k;
		scanf("%d%d", &s, &k);
		auto a = new int[s + 1]();
		printf("%3d ", a[0]);
		for (int i = 1; i <= s; i++) {
			for (int j = 1; j <= i; j *= k) {
				if (!a[i - j]) {
					a[i] = j;
					break;
				}
			}
			printf("%3d ", a[i]);
		}
		printf("\n");
		delete[] a;*/
		
		int s, k;
		scanf("%d%d", &s, &k);
		if (k % 2) {
			printf("%d\n", s % 2);
			continue;
		}
		s %= k + 1;
		if (s == k) {
			printf("%d\n", k);
			continue;
		}
		printf("%d\n", s % 2);
	}
}