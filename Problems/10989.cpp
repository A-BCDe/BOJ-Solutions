#include <stdio.h>
#include <algorithm>
int a[10001];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		a[x]++;
	}
	for (int i = 1; i < 10001; i++) {
		while (a[i]--) {
			printf("%d\n", i);
		}
	}
}