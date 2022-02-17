#include <stdio.h>
int main() {
	int n;
	scanf("%d", &n);
	auto a = new int[n + 1];
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &a[i], &a[i + 1]);
	}
	auto arr = new int* [n + 1];
	for (int i = 0; i <= n; i++) arr[i] = new int[n + 1]();
	for (int i = 0; i <= n; i++) arr[i][i] = a[i];
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= n - i; j++) {
			for (int k = j + 1; k <= i + j - 1; k++) {
				int const val = arr[k][j] + arr[i + j][k] + arr[j][j] * arr[k][k] * arr[i + j][i + j];
				if (!arr[i + j][j] || arr[i + j][j] > val) {
					arr[i + j][j] = val;
				}
			}
		}
	}
	printf("%d", arr[n][0]);
}