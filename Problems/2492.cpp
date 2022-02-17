#include <stdio.h>
#include <algorithm>
#include <utility>
using namespace std;
int main() {
	int n, m, t, k;
	scanf("%d%d%d%d", &n, &m, &t, &k);
	auto a = new pair<int, int>[t];
	auto r = new int[t];
	auto c = new int[t];
	for (int i = 0; i < t; i++) {
		scanf("%d%d", &a[i].first, &a[i].second);
		r[i] = a[i].first;
		c[i] = a[i].second;
	}
	sort(r, r + t);
	sort(c, c + t);
	sort(a, a + t);
	auto arr = new int* [t + 1];
	for (int i = 0; i <= t; i++) {
		int x;
		if (i == 0) x = 0;
		else x = r[i - 1];
		arr[i] = new int[t + 1]();
		for (int j = 0; j <= t; j++) {
			int y;
			if (j == 0) y = 0;
			else y = c[j - 1];
			if (i == 0 && j == 0) continue;
			else if (i == 0) arr[i][j] = arr[i][j - 1];
			else if (j == 0) arr[i][j] = arr[i - 1][j];
			else arr[i][j] = arr[i][j - 1] + arr[i - 1][j] - arr[i - 1][j - 1];
			if (binary_search(a, a + t, make_pair(x, y))) arr[i][j]++;
		}
	}
	int max = 0;
	for (int i = 0; i <= t; i++) {
		for (int j = 0; j <= t; j++) {
			if (i == 0 && j == 0) {
				int p = upper_bound(r, r + t, k) - r;
				int q = upper_bound(c, c + t, k) - c;
				printf("%d %d\n", p, q);
				if (max < arr[p][q]) max = arr[p][q];
			}
			else if (i == 0) {
				int p = upper_bound(r, r + t, k) - r;
				int q = upper_bound(c, c + t, k + c[j - 1]) - c;
				printf("%d %d\n", p, q);
				if (max < arr[p][q] - arr[p][j - 1]) max = arr[p][q] - arr[p][j - 1];
			}
			else if (j == 0) {
				int p = upper_bound(r, r + t, k + r[i - 1]) - r;
				int q = upper_bound(c, c + t, k) - c;
				printf("%d %d\n", p, q);
				if (max < arr[p][q] - arr[i - 1][q]) max = arr[p][q] - arr[i - 1][q];
			}
			else {
				int p = upper_bound(r, r + t, k + r[i - 1]) - r;
				int q = upper_bound(c, c + t, k + c[j - 1]) - c;
				printf("%d %d\n", p, q);
				if (max < arr[p][q] - arr[i - 1][p] - arr[q][j - 1] - arr[i - 1][j - 1])
					max = arr[p][q] - arr[i - 1][p] - arr[q][j - 1] - arr[i - 1][j - 1];
			}
		}
	}
	printf("%d", max);
	delete[] a;
}