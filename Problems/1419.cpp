#include <stdio.h>
int main() {
	int l, r, k;
	scanf("%d%d%d", &l, &r, &k);
	if (k == 2) { // 3, 4, 5, 6, ...
		if (r < 3) printf("0");
		else printf("%d", r - (l > 3 ? l : 3) + 1);
	}
	else if (k == 3) { // 6, 9, 12, 15, ...
		if (r < 6) printf("0");
		else printf("%d", r / 3 - (l > 6 ? (l + 2) : 6) / 3 + 1);
	}
	else if (k == 4) { // 10, 14, 16, 18, ...
		if (r < 10) printf("0");
		else if (r < 14) printf(l <= 10 ? "1" : "0");
		else if (l <= 10) printf("%d", r / 2 - 5);
		else if (l <= 14) printf("%d", r / 2 - 6);
		else printf("%d", r / 2 - (l + 1) / 2 + 1);
	}
	else if (k == 5) { // 15, 20, 25, 30, ...
		if (r < 15) printf("0");
		else printf("%d", r / 5 - (l > 15 ? (l + 4) : 15) / 5 + 1);
	}
}