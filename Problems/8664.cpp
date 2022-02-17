#include <stdio.h>
#include <algorithm>
#include <utility>
using namespace std;
int main() {
	pair<int, int> a[4];
	for (int i = 0; i < 4; i++) {
		scanf("%d%d", &a[i].first, &a[i].second);
	}
	sort(a, a + 4); // (0, 0) (0, 1) (1, 0) (1, 1)
	if (a[0].first == a[1].first && a[1].second == a[3].second && a[3].first == a[2].first && a[2].second == a[0].second) {
		if (a[1].second - a[0].second == a[2].first - a[0].first && a[1].second - a[0].second != 0) {
			printf("TAK");
			return 0;
		}
	}
	printf("NIE");
}