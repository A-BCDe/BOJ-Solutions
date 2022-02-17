#include <stdio.h>
#include <utility>
using namespace std;
int main() {
	int n, c;
	scanf("%d%d", &n, &c);
	pair<int, int> p = { n, n };
	for (int i = 0; i < c; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		if (x >= p.first || y >= p.second) continue;
		int first = x * p.second;
		int second = y * p.first;
		if (first >= second) {
			p.first = x;
		}
		else {
			p.second = y;
		}
	}
	printf("%d", p.first * p.second);
}