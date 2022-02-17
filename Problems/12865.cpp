#include <stdio.h>
#include <utility>
using namespace std;
int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	auto a = new pair<int, int>[n + 1];
	auto arr = new int* [n + 1];
	arr[0] = new int[k + 1]();
	int max = 0;
	for (int i = 1; i <= n; i++) {
		arr[i] = new int[k + 1]();
		scanf("%d%d", &a[i].first, &a[i].second);
		for (int j = 0; j <= k; j++) {
			arr[i][j] = arr[i - 1][j];
			if (j >= a[i].first && arr[i][j] < arr[i - 1][j - a[i].first] + a[i].second) arr[i][j] = arr[i - 1][j - a[i].first] + a[i].second;
		}
	}
	/*for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= k; j++) {
			printf("%d ", arr[i][j]);
		} printf("\n");
	}*/
	printf("%d", arr[n][k]);
}