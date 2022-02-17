#include <stdio.h>
int dfs(int* const* const a, int const n, int const cur) {
	if (cur == n) return 1;
	int res = 0;
	for (int i = 0; i < n; i++) {
		if (a[cur][i]) continue;
		for (int j = 0; j < n; j++) {
			a[cur][j]++;
			a[j][i]++;
			if (cur - i + j < n && cur - i + j >= 0) a[cur - i + j][j]++;
			if (i + cur - j < n && i + cur - j >= 0) a[i + cur - j][j]++;
		}
		res += dfs(a, n, cur + 1);
		for (int j = 0; j < n; j++) {
			a[cur][j]--;
			a[j][i]--;
			if (cur - i + j < n && cur - i + j >= 0) a[cur - i + j][j]--;
			if (i + cur - j < n && i + cur - j >= 0) a[i + cur - j][j]--;
		}
	}
	return res;
}
int main() {
	int n;
	scanf("%d", &n);
	auto a = new int* [n];
	for (int i = 0; i < n; i++) {
		a[i] = new int[n]();
	}
	printf("%d", dfs(a, n, 0));
}