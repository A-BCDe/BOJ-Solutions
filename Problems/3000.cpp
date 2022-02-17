#include <algorithm>
#include <map>
#include <stdio.h>
#include <utility>
#include <vector>
using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	auto a = new pair<int, int>[n];
	map<int, long long> x, y;
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &a[i].first, &a[i].second);
		if (x.find(a[i].first) != x.end()) x[a[i].first]++;
		else x[a[i].first] = 1;
		if (y.find(a[i].second) != y.end()) y[a[i].second]++;
		else y[a[i].second] = 1;
	}
	long long res = 0;
	for (int i = 0; i < n; i++) {
		res += (x[a[i].first] - 1) * (y[a[i].second] - 1);
	}
	printf("%lld", res);
	delete[] a;
}