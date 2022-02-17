#include <stdio.h>
int main() {
	int n;
	scanf("%d", &n);
	auto a = new int[n];
	auto b = new int[n]();
	auto c = new int[n]();
	int m = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < n; i++) {
		b[i]++; c[n - i - 1]++;
		for (int j = i + 1; j < n; j++) {
			if (a[i] < a[j]) {
				b[j] = (b[j] > b[i] ? b[j] : b[i]);
			}
			if (a[n - i - 1] < a[n - j - 1]) {
				c[n - j - 1] = (c[n - j - 1] > c[n - i - 1] ? c[n - j - 1] : c[n - i - 1]);
			}
		}
	}
	for (int i = 0; i < n; i++) {
		m = (m > (b[i] + c[i]) ? m : (b[i] + c[i]));
	}
	printf("%d", m - 1);
	delete[] a;
	delete[] b;
	delete[] c;
}