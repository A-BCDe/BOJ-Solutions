#include <stdio.h>
void dfs(int* b, int const n, int cur) {
	if (cur == n - 1) {
		int sum = 0;
		int sign = 0;
		int x = 1;
		for (int i = 0; i < n - 1; i++) {
			if (b[i] == 2) {
				x = x * 10 + i + 2;
				continue;
			}
			if (sign) { // -
				sum -= x;
			}
			else {
				sum += x;
			}
			sign = ((b[i] == 1) ? 1 : 0);
			x = i + 2;
		}
		if (sign) { // -
			sum -= x;
		}
		else {
			sum += x;
		}
		if (sum == 0) {
			for (int i = 0; i < n; i++) {
				printf("%d", i + 1);
				if (i != n - 1) {
					if (b[i] == 0) printf("+");
					else if (b[i] == 1) printf("-");
					else printf(" ");
				}
			}
			printf("\n");
		}
		return;
	}
	b[cur] = 2;
	dfs(b, n, cur + 1);
	b[cur] = 0;
	dfs(b, n, cur + 1);
	b[cur] = 1;
	dfs(b, n, cur + 1);
}
int main() {
	int tt;
	scanf("%d", &tt);
	while (tt--) {
		int n;
		scanf("%d", &n);
		auto b = new int[n - 1](); // 0 = +, 1 = -, 2 = ' '
		dfs(b, n, 0);
		printf("\n");
	}
}