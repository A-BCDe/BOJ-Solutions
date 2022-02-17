#include <stdio.h>
int a[61][61][61];
int arr[3];
int main() {
	// [a] [b] [c] = ?
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	
	for (int i = 0; i <= arr[0]; i++) {
		for (int j = 0; j <= arr[1]; j++) {
			for (int k = 0; k <= arr[2]; k++) {
				if (!i && !j && !k) continue;
				a[i][j][k] = 1000;
				int ii[3] = { (i - 1 > 0 ? i - 1 : 0), (i - 3 > 0 ? i - 3 : 0), (i - 9 > 0 ? i - 9 : 0) };
				int jj[3] = { (j - 1 > 0 ? j - 1 : 0), (j - 3 > 0 ? j - 3 : 0), (j - 9 > 0 ? j - 9 : 0) };
				int kk[3] = { (k - 1 > 0 ? k - 1 : 0), (k - 3 > 0 ? k - 3 : 0), (k - 9 > 0 ? k - 9 : 0) };
				for (int x = 0; x < 3; x++) {
					for (int y = 0; y < 3; y++) {
						for (int z = 0; z < 3; z++) {
							if (x == y || y == z || z == x) continue;
							int tmp = a[ii[x]][jj[y]][kk[z]] + 1;
							if (a[i][j][k] > tmp) a[i][j][k] = tmp;
						}
					}
				}
			}
		}
	}
	printf("%d", a[arr[0]][arr[1]][arr[2]]);
}