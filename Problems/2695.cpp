#include <stdio.h>

int arr[51][1001];

int dp(int b, int m) {
	if (arr[b][m]) return arr[b][m];
	if (b == 1) return arr[1][m] = m;
	if (m == 0) return arr[b][0] = 0;
	if (m == 1) return arr[b][1] = 1;
	int min = m;
	int mini = m;
	for (int i = 1; i <= m; i++) {
		int l = dp(b - 1, i - 1);
		int r = dp(b, m - i);
		int max = (l > r ? l : r);
		if (min > max) {
			min = max;
			mini = i;
		}
	}
	return arr[b][m] = 1 + min;
}

int main() {
	int tt;
	scanf("%d", &tt);
	while (tt--) {
		int b, m;
		scanf("%d%d", &b, &m);
		printf("%d\n", dp(b, m));
	}
}