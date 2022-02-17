#include <stdio.h>
#include <vector>
using std::vector;
constexpr int M = 998244353;
int main() {
	int n;
	scanf("%d", &n);
	auto v = new vector<int>[n + 1];
	for (int i = 1; i < n; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	
}