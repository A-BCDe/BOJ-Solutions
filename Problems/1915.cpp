#include <algorithm>
#include <stdio.h>
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	auto a = new char* [n];
	auto arr = new int* [n];
	int res = 0;
	for (int i = 0; i < n; i++) {
		a[i] = new char[m + 1];
		arr[i] = new int[m]();
		scanf("%s", a[i]);
		for (int j = 0; j < m; j++) {
			if (a[i][j] == '0') {
				arr[i][j] = 0;
				continue;
			}
			if (!i || !j) {
				arr[i][j] = 1;
				if (res == 0) res = 1;
				continue;
			}
			arr[i][j] = std::min({ arr[i - 1][j - 1], arr[i - 1][j], arr[i][j - 1] }) + 1;
			if (res < arr[i][j]) res = arr[i][j];
		}
	}
	printf("%d", res * res);
}