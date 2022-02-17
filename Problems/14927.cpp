#include <stdio.h>
int main() {
	int n;
	scanf("%d", &n);
	auto arr = new int*[n];
	for (int i = 0; i < n; i++) {
		arr[i] = new int[n];
		for (int j = 0; j < n; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	int min = -1;
	for (int i = 0; i < (1 << n); i++) {
		auto a = new int*[n];
		for (int j = 0; j < n; j++) {
			a[j] = new int[n];
			for (int k = 0; k < n; k++) {
				a[j][k] = arr[j][k];
			}
		}
		int cnt = 0;
		for (int j = 0; j < n; j++) {
			if (i & (1 << j)) {
				cnt++;
				a[0][j] = 1 - a[0][j];
				a[1][j] = 1 - a[1][j];
				if (j) a[0][j - 1] = 1 - a[0][j - 1];
				if (j < n - 1) a[0][j + 1] = 1 - a[0][j + 1];
			}
		}
		for (int j = 1; j < n; j++) {
			for (int k = 0; k < n; k++) {
				if (a[j - 1][k]) {
					cnt++;
					a[j - 1][k] = 0;
					a[j][k] = 1 - a[j][k];
					if (j < n - 1) a[j + 1][k] = 1 - a[j + 1][k];
					if (k) a[j][k - 1] = 1 - a[j][k - 1];
					if (k < n - 1) a[j][k + 1] = 1 - a[j][k + 1];
				}
			}
		}
		bool flag = true;
		for (int j = 0; j < n; j++) {
			if (a[n - 1][j]) {
				flag = false;
				break;
			}
		}
		if (!flag) continue;
		if (min == -1 || min > cnt) min = cnt;
		for (int j = 0; j < n; j++) delete[] a[j];
		delete[] a;
	}
	printf("%d", min);
}