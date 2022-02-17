#include <stdio.h>
#include <algorithm>
#include <utility>
using namespace std;
constexpr int M = 10000000;
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		auto a = new int* [n + 2];
		for (int i = 0; i < n + 2; i++) {
			a[i] = new int[n + 2];
			for (int j = 0; j < n + 2; j++) {
				a[i][j] = M;
				if (i == j) a[i][j] = 0;
			}
		}
		auto arr = new pair<int, int>[n + 2];
		for (int i = 0; i < n + 2; i++) {
			scanf("%d %d", &arr[i].first, &arr[i].second);
			for (int j = 0; j < i; j++) {
				int const x = abs(arr[i].first - arr[j].first) + abs(arr[i].second - arr[j].second);
				if (x > 1000) continue;
				a[i][j] = a[j][i] = 1;
			}
		}
		for (int i = 0; i < n + 2; i++) {
			for (int s = 0; s < n + 2; s++) {
				for (int e = 0; e < n + 2; e++) {
					if (a[s][e] > a[s][i] + a[i][e]) {
						a[s][e] = a[s][i] + a[i][e];
					}
				}
			}
		}
		if (a[0][n + 1] < M) printf("happy\n");
		else printf("sad\n");
		delete[] arr;
		for (int i = 0; i < n + 2; i++) delete[] a[i];
		delete[] a;
	}
}