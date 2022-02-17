#include <stdio.h>
int main() {
	int n;
	scanf("%d", &n);
	auto a = new int* [n];
	for (int i = 0; i < n; i++) {
		a[i] = new int[n];
		for (int j = 0; j < n; j++) {
			scanf("%d", &a[i][j]);
		}
	}
}