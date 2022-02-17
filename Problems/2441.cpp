#include <stdio.h>
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) { // i = 공백 개수
		for (int j = 0; j < i; j++) { // 공백 i번 출력
			printf(" ");
		}
		for (int j = 0; j < n - i ; j++) { // 별 n - i번 출력
			printf("*");
		}
		printf("\n");
	}
}