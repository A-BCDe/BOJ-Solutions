#include <stdio.h>
inline bool prime(int n) {
	if (n < 2) return false;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) return false;
	}
	return true;
}
int main() {
	int n, cnt = 0, x;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		cnt += prime(x);
	}
	printf("%d", cnt);
}