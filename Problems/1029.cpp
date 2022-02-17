#include <stdio.h>
int f(char const* const* a, bool* visited, int const n, int cur, int price) {
	
}
int main() {
	int n;
	scanf("%d", &n);
	auto a = new char* [n];
	for (int i = 0; i < n; i++) {
		a[i] = new char[n + 1];
		scanf("%s", a[i]);
		for (int j = 0; j < n; j++) {
			a[i][j] -= '0';
		}
	}
	auto arr = new int** [n];
	for (int i = 0; i < n; i++) {
		arr[i] = new int*[n];
		for (int j = 0; j < n; j++) {
			arr[i][j] = new int[n]();
		}
	}
	arr[0][0][0] = 1; // times, cur peop, cur cost, passed up to now
	for (int i = 1; i < n; i++) {
		bool flag = false;
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				if (j == k) continue;
				for (int l = 0; l <= a[j][k]; l++) {
					if ((1 << (k - 1)) & arr[i - 1][j][l]) continue;
					arr[i][k][a[j][k]] = arr[i - 1][j][l]
				}
			}
		}
	}
}