#include <cstdint>
#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	auto a = new int[n];
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	int max;
	scanf("%d", &max);
	auto visited = new bool[a[n - 1] * max + 1]();
	auto b = new uint16_t[a[n - 1] * max + 1]();
	visited[0] = true;
	for (int i = 0;; i++) {
		if (!visited[i]) {
			printf(i % 2 ? "jjaksoon" : "holsoon");
			printf(" win at %d", i);
			return 0;
		}
		//printf("b[%3d]\t= %d\n", i, b[i]);
		if (b[i] < max) {
			for (int j = 0; j < n; j++) {
				if (!visited[i + a[j]]) {
					visited[i + a[j]] = true;
					b[i + a[j]] = b[i] + 1;
				}
				else if (b[i + a[j]] > b[i] + 1) b[i + a[j]] = b[i] + 1;
			}
		}
	}
	delete[] b;
	delete[] visited;
	delete[] a;
}