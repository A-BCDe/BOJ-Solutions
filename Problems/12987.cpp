#include <stdio.h>
inline void delete_mat(int** A, int n) {
	for (int i = 0; i < n; i++) {
		delete[] A[i];
	} delete[] A;
}
inline int** ID(int n) {
	auto R = new int*[n];
	for (int i = 0; i < n; i++) {
		R[i] = new int[n];
		for (int j = 0; j < n; j++) {
			R[i][j] = (i == j);
		}
	} return R;
}
inline int** add(int** A, int** B, int n, int m) {
	auto R = new int*[n];
	for (int i = 0; i < n; i++) {
		R[i] = new int[n];
		for (int j = 0; j < n; j++) {
			R[i][j] = ((A[i][j] + B[i][j]) % m + m) % m;
		}
	}
	return R;
}
inline int** add_id(int** A, int n, int m) {
	auto R = new int*[n];
	for (int i = 0; i < n; i++) {
		R[i] = new int[n];
		for (int j = 0; j < n; j++) {
			R[i][j] = (A[i][j] + (i == j)) % m;
		}
	}
	return R;
}
inline int** mul(int** A, int** B, int n, int m) {
	auto R = new int*[n];
	for (int i = 0; i < n; i++) {
		R[i] = new int[n]();
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				R[i][j] += (A[i][k] * B[k][j]) % m + m;
				R[i][j] %= m;
			}
		}
	}
	return R;
}
inline int** power(int** A, int n, int k, int m) {
	if (!k) return ID(n);
	if (k == 1) {
		auto R = new int*[n];
		for (int i = 0; i < n; i++) {
			R[i] = new int[n];
			for (int j = 0; j < n; j++) {
				R[i][j] = A[i][j];
			}
		} return R;
	}
	auto R = power(A, n, k >> 1, m);
	auto B = mul(R, R, n, m);
	delete_mat(R, n);
	R = power(A, n, k & 1, m);
	auto C = mul(B, R, n, m);
	delete_mat(B, n);
	delete_mat(R, n);
	return C;
}
int** calc(int** A, int n, int k, int m) {
	if(k == 1) {
		auto R = new int*[n];
		for (int i = 0; i < n; i++) {
			R[i] = new int[n];
			for (int j = 0; j < n; j++) {
				R[i][j] = A[i][j];
			}
		}
		return R;
	}
	auto B = calc(A, n, k >> 1, m);
	if (k & 1) {
		auto C = power(A, n, (k >> 1) + 1, m);
		auto D = add(A, C, n, m);
		delete_mat(C, n);
		C = mul(D, B, n, m);
		delete_mat(D, n);
		delete_mat(B, n);
		D = add(A, C, n, m);
		delete_mat(C, n);
		return D;
	}
	auto C = power(A, n, (k >> 1), m);
	auto D = add_id(C, n, m);
	delete_mat(C, n);
	C = mul(D, B, n, m);
	delete_mat(B, n);
	delete_mat(D, n);
	return C;
}
int main() {
	int n, k, m;
	scanf("%d%d%d", &n, &k, &m);
	auto A = new int*[n];
	for (int i = 0; i < n; i++) {
		A[i] = new int[n];
		for (int j = 0; j < n; j++) {
			scanf("%d", &A[i][j]);
			A[i][j] = (A[i][j] % m + m) % m;
		}
	}
	auto R = calc(A, n, k, m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", R[i][j]);
		} printf("\n");
		delete[] R[i]; delete[] A[i];
	} delete[] R; delete[] A;
}