#include <stdio.h>
int main() {
	int n;
	scanf("%d", &n);
	auto a = new int[n + 1];
	auto b = new int[n + 1];
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		b[a[i]] = i;
	}
	// 5 4 3 2 1
	// 4 3 2 1 5
	// 3 2 1 4 5
	// 2 1 3 4 5
	// 1 2 3 4 5
	
	// 1 2 5 4 3
	// 2 5 4 1 3
	// 5 4 1 2 3
	// 4 1 2 3 5
	// 1 2 3 4 5

	// 1 3 2 5 4
	// 3 2 5 1 4

	while (true) {
		int idx = a[0];
		for (; idx <= n; idx++) {
			
		}
		if (idx == n + 1) {

		}
	}

	delete[] b;
	delete[] a;
}