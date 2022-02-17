#include <stdio.h>
#include <utility>
using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	auto a = new pair<int, int>[n + 1];
	for (int i = 1; i <= n; i++) {
		scanf("%d%d\n", &a[i].first, &a[i].second);
	}
	auto arr = new int* [n + 1];
	for (int i = 0; i <= n; i++) {
		arr[i] = new int[62501];

	}
	
	for (int i = 0; i <= n; i++) {
		delete[] arr[i];
	}
	delete[] arr;
	delete[] a;
}