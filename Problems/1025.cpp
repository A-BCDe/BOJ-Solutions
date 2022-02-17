#include <stdio.h>
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	auto a = new char* [n];
	for (int i = 0; i < n; i++) {
		a[i] = new char[m + 1];
		scanf("%s", &a[i]);
	}

}