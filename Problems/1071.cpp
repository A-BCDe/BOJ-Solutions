#include <stdio.h>
#include <algorithm>
int main() {
	int n;
	scanf("%d", &n);
	auto a = new int[n];
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	std::sort(a, a + n);
	auto res = new int[n]();
	auto visited = new bool[n]();
	bool flag = false;
	int kdx;
	for (int i = 0; i < n; i++) {
		int idx = 0;
		for (; idx < n; idx++) {
			if (visited[idx]) continue;
			break;
		}
		if (i && res[i - 1] == a[idx]) {
			res[i] = a[idx];
			visited[idx] = true;
			continue;
		}
		if (flag) {
			if (res[i - 1] == a[idx]) {
				res[i] = a[idx];
				visited[idx] = true;
				continue;
			}
			res[i] = a[kdx];
			flag = false;
			visited[kdx] = true;
			continue;
		}
		int jdx = idx + 1;
		for (; jdx < n; jdx++) {
			if (visited[jdx]) continue;
			if (a[idx] < a[jdx]) break;
		}
		if (jdx == n) {
			res[i] = a[idx];
			visited[idx] = true;
			continue;
		}
		if (a[idx] + 1 != a[jdx]) {
			res[i] = a[idx];
			visited[idx] = true;
			continue;
		}
		kdx = jdx + 1;
		for (; kdx < n; kdx++) {
			if (visited[kdx]) continue;
			if (a[jdx] < a[kdx]) break;
		}
		if (kdx == n) {
			res[i] = a[jdx];
			visited[jdx] = true;
			continue;
		}
		res[i] = a[idx];
		visited[idx] = true;
		flag = true;
	}
	for (int i = 0; i < n; i++) {
		printf("%d ", res[i]);
	}
	delete[] visited;
	delete[] res;
	delete[] a;
}