#include <stdio.h>
int main() {
	int a, b, d, n;
	scanf("%d%d%d%d", &a, &b, &d, &n);
	auto arr = new int[n]();
	auto arra = new int[n]();
	auto arrb = new int[n]();
	arr[0] = 1;
	int total = 1;
	for (int i = 0; i < n; i++) {
		if (i >= a) {
			arra[i] = arr[i - a];

		}
		if (i >= b) {
			arrb[i] = arra[i - a + a];
		}
		if (i >= d) {
			total -= arr[i - d];
		}
		total = (arr[i] + arra[i] + arrb[i] + total) % 1000;
		printf("arr:\n");
		for (int i = 0; i < n; i++) {
			printf("%d ", arr[i]);
		} printf("\narra:\n");
		for (int i = 0; i < n; i++) {
			printf("%d ", arra[i]);
		} printf("\narrb:\n");
		for (int i = 0; i < n; i++) {
			printf("%d ", arrb[i]);
		} printf("\n");
	}
	printf("%d", total);
	delete[] arrb;
	delete[] arra;
	delete[] arr;
}