#include <stdio.h>
int main() {
	bool b[42] = {};
	for (int i = 0; i < 10; i++) {
		int x; scanf("%d", &x);
		b[x % 42] = true;
	}
	int cnt = 0;
	for (int i = 0; i < 42; i++) {
		if (b[i])cnt++;
	}
	printf("%d", cnt);
}