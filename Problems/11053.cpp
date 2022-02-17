#include <stdio.h>
int main() {
	int n;
	scanf("%d", &n);
	auto a = new int[n];
	auto b = new int[n]();
	int m = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < n; i++) {
		b[i] += 1;
		for (int j = i + 1; j < n; j++) {
			if (a[i] < a[j]) {
				b[j] = (b[i] > b[j] ? b[i] : b[j]);
			}
		}
		m = m > b[i] ? m : b[i];
	}
	printf("%d", m);
	delete[] a;
	delete[] b;
}