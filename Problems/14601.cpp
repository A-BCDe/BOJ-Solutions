#include <stdio.h>
void make(int* const* a, int x, int y, int curx, int cury, int k, int& idx) {
	if (!k) {
		a[curx][cury] = -1;
		return;
	}
	if (x < curx + (1 << (k - 1))) {
		if (y < cury + (1 << (k - 1))) {
			make(a, x, y, curx, cury, k - 1, idx); // left down
			make(a, curx + (1 << (k - 1)) - 1, cury + (1 << (k - 1)), curx, cury + (1 << (k - 1)), k - 1, idx); // left up
			make(a, curx + (1 << (k - 1)), cury + (1 << (k - 1)) - 1, curx + (1 << (k - 1)), cury, k - 1, idx); // right down
			make(a, curx + (1 << (k - 1)), cury + (1 << (k - 1)), curx + (1 << (k - 1)), cury + (1 << (k - 1)), k - 1, idx); // right up
			idx++;
			a[curx + (1 << (k - 1)) - 1][cury + (1 << (k - 1))] = idx; // left up
			a[curx + (1 << (k - 1))][cury + (1 << (k - 1)) - 1] = idx; // right down
			a[curx + (1 << (k - 1))][cury + (1 << (k - 1))] = idx; // right up
		}
		else {
			make(a, curx + (1 << (k - 1)) - 1, cury + (1 << (k - 1)) - 1, curx, cury, k - 1, idx); // left down
			make(a, x, y, curx, cury + (1 << k), k - 1, idx); // left up
			make(a, curx + (1 << (k - 1)), cury + (1 << (k - 1)) - 1, curx + (1 << (k - 1)), cury, k - 1, idx); // right down
			make(a, curx + (1 << (k - 1)), cury + (1 << (k - 1)), curx + (1 << (k - 1)), cury + (1 << (k - 1)), k - 1, idx); // right up
			idx++;
			a[curx + (1 << (k - 1)) - 1][cury + (1 << (k - 1)) - 1] = idx; // left down
			a[curx + (1 << (k - 1))][cury + (1 << (k - 1)) - 1] = idx; // right down
			a[curx + (1 << (k - 1))][cury + (1 << (k - 1))] = idx; // right up
		}
	}
	else {
		if (y < cury + (1 << (k - 1))) {
			make(a, curx + (1 << (k - 1)) - 1, cury + (1 << (k - 1)) - 1, curx, cury, k - 1, idx); // left down
			make(a, curx + (1 << (k - 1)) - 1, cury + (1 << (k - 1)), curx, cury + (1 << (k - 1)), k - 1, idx); // left up
			make(a, x, y, curx + (1 << (k - 1)), cury, k - 1, idx); // right down
			make(a, curx + (1 << (k - 1)), cury + (1 << (k - 1)), curx + (1 << (k - 1)), cury + (1 << (k - 1)), k - 1, idx); // right up
			idx++;
			a[curx + (1 << (k - 1)) - 1][cury + (1 << (k - 1)) - 1] = idx; // left down
			a[curx + (1 << (k - 1)) - 1][cury + (1 << (k - 1))] = idx; // left up
			a[curx + (1 << (k - 1))][cury + (1 << (k - 1))] = idx; // right up
		}
		else {
			make(a, curx + (1 << (k - 1)) - 1, cury + (1 << (k - 1)) - 1, curx, cury, k - 1, idx); // left down
			make(a, curx + (1 << (k - 1)) - 1, cury + (1 << (k - 1)), curx, cury + (1 << (k - 1)), k - 1, idx); // left up
			make(a, curx + (1 << (k - 1)), cury + (1 << (k - 1)) - 1, curx + (1 << (k - 1)), cury, k - 1, idx); // right down
			make(a, x, y, curx + (1 << (k - 1)), cury + (1 << (k - 1)), k - 1, idx); // right up
			idx++;
			a[curx + (1 << (k - 1)) - 1][cury + (1 << (k - 1)) - 1] = idx; // left down
			a[curx + (1 << (k - 1)) - 1][cury + (1 << (k - 1))] = idx; // left up
			a[curx + (1 << (k - 1))][cury + (1 << (k - 1)) - 1] = idx; // right down
		}
	}
	for (int i = (1 << k) - 1; i >= 0; i--) { // x
		for (int j = 0; j < (1 << k); j++) { // y
			printf("%d ", a[cury + j][curx + i]);
		} printf("\n");
	} printf("\n");
}
int main() {
	int k, x, y;
	scanf("%d%d%d", &k, &x, &y);
	auto a = new int*[1 << k];
	for (int i = 0; i < (1 << k); i++) {
		a[i] = new int[1 << k];
	}
	int idx = 1;
	make(a, x - 1, y - 1, 0, 0, k, idx);

	for (int i = (1 << k) - 1; i >= 0; i--) { // x
		for (int j = 0; j < (1 << k); j++) { // y
			printf("%d ", a[j][i]);
		} printf("\n");
	}
}