#include <stdio.h>
#include <set>
int power(int n, int p) {
	int res = 1;
	for (int i = 0; i < p; i++) {
		res *= n;
	} return res;
}
inline int next(int n, int p) {
	int res = 0;
	while (n) {
		int const x = n % 10;
		res += power(x, p);
		n /= 10;
	} return res;
}
int main() {
	int a, p;
	scanf("%d%d", &a, &p);
	std::set<int> s;
	while (s.insert(a).second) a = next(a, p);
	while (!s.insert(a).second) {
		s.erase(a);
		a = next(a, p);
	}
	printf("%zu", s.size() - 1);
}