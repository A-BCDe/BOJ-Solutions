#include <stdio.h>
#include <algorithm>
#include <set>
using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	auto a = new long long[n];
	for (int i = 0; i < n; i++) {
		scanf("%lld", &a[i]);
	}
	sort(a, a + n);
	set<int> add, sub;
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			if (add.find(a[i] + a[j]) == add.end()) add.insert(a[i] + a[j]);
			if (sub.find(a[j] - a[i]) == sub.end()) sub.insert(a[j] - a[i]);
		}
	}
	int max = 0;
	for (auto it : add) {
		if (sub.find(it) != sub.end()) {
			for (int i = n - 1; a[i] > it && i > max; i--) {
				if (binary_search(a, a + n, a[i] - it)) max = i;
			}
		}
	}
	printf("%lld", a[max]);
	delete[] a;
}