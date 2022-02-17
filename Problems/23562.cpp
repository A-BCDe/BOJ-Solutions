#include <stdio.h>
int main() {
	int n, m, a, b;
	scanf("%d%d%d%d", &n, &m, &a, &b);
	auto change = new bool* [n];
	auto arr = new char* [n];
	for (int i = 0; i < n; i++) {
		arr[i] = new char[m + 1];
		change[i] = new bool[m];
		scanf("%s", arr[i]);
	}

}