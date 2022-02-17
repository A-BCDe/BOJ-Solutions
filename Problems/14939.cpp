#include <stdio.h>
int main() {
	char a[10][11];
	char c[10][11];
	for (int i = 0; i < 10; i++) {
		scanf("%s", a[i]);
		for (int j = 0; j < 10; j++) {
			if (a[i][j] == '#') a[i][j] = 0;
			else a[i][j] = 1;
		}
	}
	int res = 1000;
	for (int i = 0; i < (1 << 10); i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k < 10; k++) {
				c[j][k] = a[j][k];
			}
		}
		int cnt = 0;
		for (int j = 0; j < 10; j++) {
			if (i & (1 << j)) {
				cnt++;
				c[0][j] = 1 - c[0][j];
				c[1][j] = 1 - c[1][j];
				if (j) c[0][j - 1] = 1 - c[0][j - 1];
				if (j < 9) c[0][j + 1] = 1 - c[0][j + 1];
			}
		}
		for (int j = 1; j < 10; j++) {
			for (int k = 0; k < 10; k++) {
				if (c[j - 1][k]) {
					cnt++;
					c[j - 1][k] = 0;
					c[j][k] = 1 - c[j][k];
					if (k) c[j][k - 1] = 1 - c[j][k - 1];
					if (k < 9) c[j][k + 1] = 1 - c[j][k + 1];
					if (j < 9) c[j + 1][k] = 1 - c[j + 1][k];
				}
			}
		}
		bool flag = false;
		for (int j = 0; j < 10; j++) {
			if (c[9][j]) {
				flag = true; break;
			}
		}
		if (!flag) {
			if (res > cnt) res = cnt;
		}
	}
	if (res == 1000) {
		printf("-1");
	}
	else printf("%d", res);
}