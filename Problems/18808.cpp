#include <stdio.h>
int main() {
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	auto board = new bool* [n];
	for (int i = 0; i < n; i++) {
		board[i] = new bool[m]();
	}
	for (int i = 0; i < k; i++) {
		int r, c;
		scanf("%d%d", &r, &c);
		auto original = new bool* [r];
		
		
		for (int j1 = 0; j1 < r; j1++) {
			original[j1] = new bool[c];
			for (int j2 = 0; j2 < c; j2++) {
				int x;
				scanf("%d", &x);
				original[j1][j2] = (x == 1);
			}
		}

		bool** sticker;
		int rotate = 0;
		int cur_r, cur_c;
		bool done = false;
	LOOP:

		if (rotate & 1) {
			cur_r = c;
			cur_c = r;
		}
		else {
			cur_r = r;
			cur_c = c;
		}
		sticker = new bool* [cur_r];
		for (int x = 0; x < cur_r; x++) {
			sticker[x] = new bool[cur_c];
			for (int y = 0; y < cur_c; y++) {
				switch (rotate) {
				case 0: sticker[x][y] = original[x][y]; break;
				case 1: sticker[x][y] = original[cur_c - y - 1][x]; break;
				case 2: sticker[x][y] = original[cur_r - x - 1][cur_c - y - 1]; break;
				case 3: sticker[x][y] = original[y][cur_r - x - 1]; break;
				}
			}
		}

		if (n < cur_r || m < cur_c) goto ROTATE;
		for (int j1 = 0; j1 <= n - cur_r; j1++) {
			for (int j2 = 0; j2 <= m - cur_c; j2++) {
				bool flag = false;
				for (int x = 0; x < cur_r && !flag; x++) {
					for (int y = 0; y < cur_c && !flag; y++) {
						if (sticker[x][y]) {
							if (board[j1 + x][j2 + y]) {
								flag = true;
								break;
							}
						}
					}
				}
				if (!flag) {
					for (int x = 0; x < cur_r; x++) {
						for (int y = 0; y < cur_c; y++) {
							board[j1 + x][j2 + y] = board[j1 + x][j2 + y] || sticker[x][y];
						}
					}
					done = true;
					goto ROTATE;
				}
			}
		}

	ROTATE:
		for (int x = 0; x < ((rotate & 1) ? c : r); x++) {
			delete[] sticker[x];
		}
		delete[] sticker;
		if (!done && rotate != 3) { rotate++; goto LOOP; }

		for (int x = 0; x < r; x++) {
			delete[] original[x];
		}
		delete[] original;
	}
	int res = 0;
	for (int x = 0; x < n; x++) {
		for (int y = 0; y < m; y++) {
			res += (board[x][y] ? 1 : 0);
		}
		delete[] board[x];
	}
	printf("%d", res);
	delete[] board;
}