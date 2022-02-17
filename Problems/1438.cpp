#include <stdio.h>
#include <algorithm>
#include <array>
#include <map>
#include <set>
#include <vector>
#include <utility>
using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	auto a = new pair<int, int>[n];
	vector<int> col, row;
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &a[i].first, &a[i].second);
		col.push_back(a[i].first);
		row.push_back(a[i].second);
	}
	sort(a, a + n);
	sort(col.begin(), col.end());
	sort(row.begin(), row.end());
	vector<int> co, ro;
	for (int i = 0; i < col.size(); i++) {
		while (i < col.size() - 1 && col[i] == col[i + 1]) i++;
		co.push_back(col[i]);
	}
	for (int i = 0; i < row.size(); i++) {
		while (i < row.size() - 1 && row[i] == row[i + 1]) i++;
		ro.push_back(row[i]);
	}
	auto arr = new int* [co.size()];
	for (int i = 0; i < co.size(); i++) {
		arr[i] = new int[ro.size()]();
	}
	for (int i = 0; i < co.size(); i++) {
		for (int j = 0; j < ro.size(); j++) {
			if (i > 0) arr[i][j] = arr[i - 1][j];
			if (j > 0) arr[i][j] += arr[i][j - 1];
			if (i > 0 && j > 0) arr[i][j] -= arr[i - 1][j - 1];
			if (binary_search(a, a + n, make_pair(co[i], ro[j]))) {
				printf("(%d, %d) found\n", co[i], ro[j]);
				arr[i][j]++;
			}
		}
	}
	
	for (int i = 0; i < co.size(); i++) {
		for (int j = 0; j < ro.size(); j++) {
			printf("%3d ", arr[i][j]);
		}
		printf("\n");
	}
	int min = 211111111;
	for (int i = 0; i < co.size(); i++) { // col, left
		for (int j = i; j < co.size(); j++) { // col, right
			for (int k = 0; k < ro.size(); k++) { // row, right
				int l = 0, r = k + 1;
				while (l < r) {
					int const m = (l + r) / 2; // row, left
					int point_cnt = arr[j][k];
					if (m > 0) point_cnt -= arr[j][m - 1];
					if (i > 0) point_cnt -= arr[i - 1][k];
					if (i > 0 && m > 0) point_cnt += arr[i - 1][m - 1];
					printf("(%d, %d), (%d, %d) : %d\n", i, m, j, k, point_cnt);
					if (point_cnt < n / 2) r = m;
					else {
						int size = (co[j] - co[i] + 2) * (ro[k] - ro[m] + 2);
						if (min > size) min = size;
						l = m + 1;
 					}
				}
			}
		}
	}
	printf("%d", min);
	for (int i = 0; i < co.size(); i++) {
		delete[] arr[i];
	}
	delete[] arr;
	delete[] a;
}