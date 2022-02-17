#include <algorithm>
#include <stdio.h>
using namespace std;
struct str { int start, end, cap; };
bool comp(str const& a, str const& b) { return a.end < b.end || (a.end == b.end && a.start < b.start); }
int main() {
	int n, c, m;
	scanf("%d%d%d", &n, &c, &m);
	auto a = new str[m];
	for (int i = 0; i < m; i++) scanf("%d%d%d", &a[i].start, &a[i].end, &a[i].cap);
	sort(a, a + m, comp);
	auto arr = new int[n + 1]();
	int res = 0;
	for (int i = 0; i < m; i++) {
		int max = 0;
		for (int j = a[i].start; j != a[i].end; j++) {
			if (max < arr[j]) max = arr[j];
		}
		int cap = c - max;
		if (cap > a[i].cap) cap = a[i].cap;
		for (int j = a[i].start; j != a[i].end; j++) arr[j] += cap;
		res += cap;
	}
	printf("%d", res);
	delete[] arr;
	delete[] a;
}