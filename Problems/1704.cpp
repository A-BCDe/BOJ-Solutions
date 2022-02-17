#include <stdio.h>
int main() {
	int m, n;
	scanf("%d%d", &m, &n);
	auto a = new int*[m];
	for (int i = 0; i < m; i++) {
		a[i] = new int[n];
		for (int j = 0; j < n; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	int cntflipped = n * m + 1;
	int** resflipped = nullptr;
	for (int i = 0; i < (1 << n); i++) {
		int cnt = 0;
		auto flipped = new int*[m];
		auto arr = new int*[m];
		for (int j = 0; j < m; j++) {
			flipped[j] = new int[n]();
			arr[j] = new int[n];
			for (int k = 0; k < n; k++) {
				arr[j][k] = a[j][k];
			}
		}
		for (int j = 0; j < n; j++) {
			if (i & (1 << (n - j - 1))) {
				cnt++;
				flipped[0][j] = 1;
				arr[0][j] = 1 - arr[0][j];
				if (m > 1) arr[1][j] = 1 - arr[1][j];
				if (j) arr[0][j - 1] = 1 - arr[0][j - 1];
				if (j < n - 1) arr[0][j + 1] = 1 - arr[0][j + 1];
			}
		}

		for (int j = 1; j < m; j++) {
			for (int k = 0; k < n; k++) {
				if (arr[j - 1][k]) {
					cnt++;
					flipped[j][k] = 1;
					arr[j - 1][k] = 0;
					arr[j][k] = 1 - arr[j][k];
					if (k) arr[j][k - 1] = 1 - arr[j][k - 1];
					if (k < n - 1) arr[j][k + 1] = 1 - arr[j][k + 1];
					if (j < m - 1) arr[j + 1][k] = 1 - arr[j + 1][k];
				}
			}
		}
		bool flag = false;
		for (int j = 0; j < n; j++) {
			if (arr[m - 1][j]) {
				flag = true;
				break;
			}
		}
		if (!flag && cnt < cntflipped) {
			if (!resflipped) {
				for (int j = 0; j < m; j++) delete[] resflipped;
			}
			resflipped = flipped;
			cntflipped = cnt;
		}
		else {
			for (int j = 0; j < m; j++) delete[] arr[j], delete[] flipped[j];
			delete[] arr;
			delete[] flipped;
		}
	}
	if (resflipped) {
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < n; k++) {
				printf("%d ", resflipped[j][k]);
			} printf("\n");
		}
		return 0;
	}
	printf("IMPOSSIBLE");
}