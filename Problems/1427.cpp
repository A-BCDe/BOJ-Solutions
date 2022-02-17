#include <algorithm>
#include <stdio.h>
#include <string.h>
int main() {
	char a[12];
	scanf("%s", a);
	auto const l = strlen(a);
	std::sort(a, a + l);
	for (int i = l - 1; i >= 0; i--) {
		printf("%c", a[i]);
	}
}