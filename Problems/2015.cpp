#include <stdio.h>
#include <map>
int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	std::map<int, int> m;
	int s = 0;
	long long res = 0;
	while (n--) {
		int x;
		scanf("%d", &x);
		s += x;
		res += (s == k);
		res += m[s - k];
		m[s]++;
	}
	printf("%lld", res);
}