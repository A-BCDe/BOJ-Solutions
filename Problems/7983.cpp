#include <stdio.h>
#include <algorithm>
#include <utility>
using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	auto a = new pair<int, int>[n];
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &a[i].second, &a[i].first);
	}
	sort(a, a + n);
	int max = 1000000001;
	for (int i = n - 1; i >= 0; i--) {
		if (a[i].first <= max) {
			max = a[i].first - a[i].second;
		}
		else {
			max -= a[i].second;
		}
	}
	printf("%d", max);
	delete[] a;
}