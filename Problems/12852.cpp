#include <stdio.h>
#include <utility>
using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	auto a = new pair<int, int>[n + 1];
	a[1] = { 0, 0 };
	for (int i = 2; i <= n; i++) {
		a[i] = { i - 1, a[i - 1].second + 1 }; // prev, dist
		if (i % 2 == 0 && a[i].second > a[i / 2].second + 1) a[i] = { i / 2, a[i / 2].second + 1 };
		if (i % 3 == 0 && a[i].second > a[i / 3].second + 1) a[i] = { i / 3, a[i / 3].second + 1 };
	}
	printf("%d\n%d ", a[n].second, n);
	while (n != 1) {
		printf("%d ", n = a[n].first);
	}
}