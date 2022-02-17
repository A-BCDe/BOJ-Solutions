#include <algorithm>
#include <stdio.h>
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	auto a = new int[n];
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		if (a[i] < 0) a[i] = -a[i];
	}
	std::sort(a, a + n);

}