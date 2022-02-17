#include <stdio.h>
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		// n개를 입력해야 한다
		// 
		// i번째 줄에서
		// 공백 : n - (i + 1)
		// 별   : i + 1
		// for (int i = 0; i < n; i++) -> n번 돈다.
		for (int j = 0; j < n - i - 1; j++) {
			printf(" ");
		}
		for (int j = 0; j < i + 1; j++) {
			printf("*");
		}
		printf("\n");
	}
}