#include <stdio.h>
int main() {
	int n, k, d;
	scanf("%d%d%d", &n, &k, &d);
	auto arr = new int* [k];
	for (int i = 0; i < k; i++) {
		arr[i] = new int[3];
		scanf("%d%d%d", &arr[i][0], &arr[i][1], &arr[i][2]);
	}
	int l = 0, r = 1000001;
	int res = 0;
	while (l < r) {
		auto const m = (l + r) / 2;
		long long sum = 0;
		for (int i = 0; i < k; i++) {
			if (m < arr[i][0]) continue;
			int x = (arr[i][1] > m ? m : arr[i][1]);
			sum += (x - arr[i][0]) / arr[i][2] + 1;
		}
		if (sum >= d) {
			res = m;
			r = m;
		}
		else {
			l = m + 1;
		}
	}
	printf("%d", res);
}