#include <algorithm>
#include <numeric>
#include <stdio.h>
void row_exchange(int** A, int* b, int n, int x, int y) {
	if (x == y) return;
	for (int i = 0; i < n; i++) std::swap(A[x][i], A[y][i]);
	std::swap(b[x], b[y]);
}
void row_mul_and_add(int** A, int* b, int n, int from, int to, int mul) {
	for (int i = 0; i < n; i++) A[to][i] += A[from][i] * mul;
	b[to] += b[from] * mul;
}
void row_zeroize(int** A, int* b, int n, int piv, int l, int r) {
	if (A[std::max(l, r)][piv] == 0) return;
	if (A[std::min(l, r)][piv] == 0) {
		row_exchange(A, b, n, l, r);
		return;
	}
	int const mul = -(A[r][piv] / A[l][piv]);
	row_mul_and_add(A, b, n, l, r, mul);
	row_zeroize(A, b, n, piv, r, l);
}
int main() {
	int n;
	scanf("%d", &n);
	auto A = new int*[n];
	auto b = new int[n];
	for (int i = 0; i < n; i++) {
		A[i] = new int[n];
		for (int j = 0; j < n; j++) {
			scanf("%d", &A[i][j]);
		}
		scanf("%d", &b[i]);
	}
	int piv = 0;
	while (piv < n) {
		for (int i = piv; i < n; i++) {
			int g = A[i][piv];
			for (int j = piv + 1; j < n; j++) g = std::gcd(g, A[i][j]);
			g = std::gcd(g, b[i]);
			for (int j = piv; j < n; j++) A[i][j] /= g;
			b[i] /= g;
			if (A[i][piv] < 0) {
				for (int j = piv; j < n; j++) A[i][j] = -A[i][j];
				b[i] = -b[i];
			}
		}

		for (int i = piv; i < n; i++) {
			if (A[i][piv] != 0) {
				row_exchange(A, b, n, piv, i);
				break;
			}
		}

		for (int i = piv + 1; i < n; i++) {
			row_zeroize(A, b, n, piv, piv, i);
		}
		/*
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				printf("%d ", A[i][j]);
			} printf("%d\n", b[i]);
		} printf("\n");
		*/
		piv++;
	}

	auto sol = new int[n]();
	for (int i = n - 1; i >= 0; i--) {
		int sum = 0;
		for (int j = i + 1; j < n; j++) {
			sum += A[i][j] * sol[j];
		}
		sol[i] = (b[i] - sum) / A[i][i];
	}
	for (int i = 0; i < n; i++) {
		printf("%d ", sol[i]);
	}
}