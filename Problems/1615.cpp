#include <stdio.h>
#include <algorithm>
#include <utility>
using namespace std;
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	auto a = new pair<int, int>[m];
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &a[i].first, &a[i].second);
	}
	sort(a, a + m);
	for (int i = 0; i < m; i++) {
		
	}
}