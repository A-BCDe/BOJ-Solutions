#include <stdio.h>
int main() {
	int n, d, k, c;
	scanf("%d%d%d%d", &n, &d, &k, &c);
	auto visited = new int[d + 1]();
	int cnt = 0;
	auto a = new int[n]();
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < k; i++) {
		if (!(visited[a[i]])) {
			cnt++;
		}
		visited[a[i]]++;
	}
	int mx = 0;
	for (int i = 0; i <= n; i++) {
		if (visited[c]) {
			if (mx < cnt) {
				mx = cnt;
			}
		}
		else {
			if (mx < cnt + 1) {
				mx = cnt + 1;
			}
		}
		if (--visited[a[i % n]] == 0) {
			cnt--;
		}
		if (!visited[a[(i + k) % n]]++) cnt++;
	}
	// 1 ~ k
	for (int i = 1; i <= n + 1; i++) {
		if (visited[c]) {
			if (mx < cnt) {
				mx = cnt;
			}
		}
		else {
			if (mx < cnt + 1) {
				mx = cnt + 1;
			}
		}
		if (--visited[a[i % n]] == 0) {
			cnt--;
		}
		if(!visited[a[(i + k) % n]]++) cnt++;
	}
	printf("%d", mx);
	delete[] a;
	delete[] visited;
}