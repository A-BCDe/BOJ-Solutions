#include <iostream>
#include <string.h>
int main() {
	int tt;
	scanf("%d", &tt);
	while (tt--) {
		char c[210];
		scanf("%s", c);
		auto l = strlen(c);
		int i = 0;
		while (i < l) {
			if (c[i++] == '1') {
				if (c[i++] != '0') goto F;
				if (c[i++] != '0') goto F;
			A:
				while (c[i] == '0') i++;
				if (c[i++] != '1') { i--; goto F; }
				bool flag = false;
				while (c[i] == '1') { flag = true; i++; }
				if (c[i + 1] == '1') continue;
				if (c[i] == 0) break;
				if (!flag) goto F;
				i--;
				continue;
			}
			else {
				if (c[i++] != '1') goto F;
			}
		}
		printf("YES\n");
		continue;
	F:
		printf("NO\n");
	}
}