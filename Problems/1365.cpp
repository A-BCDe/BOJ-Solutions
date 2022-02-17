#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	vector<int> v;
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		if (v.empty() || v.back() < x) v.push_back(x);
		else *lower_bound(v.begin(), v.end(), x) = x;
	}
	printf("%d", n - v.size());
}