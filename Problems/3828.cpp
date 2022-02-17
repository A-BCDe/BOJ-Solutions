#include <cassert>
#include <cmath>
#include <cstdio>
using ld = long double;
ld** make_mat(int matrix_size, int idx) {
	auto mat = new ld*[matrix_size];
	for (int i = 0; i < matrix_size; i++) {
		mat[i] = new ld[matrix_size]();
		mat[i][0] = 1;
		int const c = i + (i >= idx);
		int mul = c;
		for (int j = 1; j < matrix_size; j++) {
			mat[i][j] = mul;
			mul *= c;
		}
	}
	return mat;
}
ld* calc(ld** mat, ld* a, int idx, int matrix_size) {
	auto vec = new ld[matrix_size];
	for (int i = 0; i < matrix_size; i++) {
		vec[i] = a[i + (i >= idx)];
	}
	for (int i = 0; i < matrix_size; i++) {
		// mat(i, i) != 0
		auto piv = mat[i][i];
		assert(piv != 0);
		vec[i] /= piv;
		mat[i][i] = 1;
		for (int j = i + 1; j < matrix_size; j++) mat[i][j] /= piv;
		for (int j = 0; j < matrix_size; j++) {
			if (i == j) continue;
			ld mul = mat[j][i];
			mat[j][i] = 0;
			for (int k = i + 1; k < matrix_size; k++) {
				mat[j][k] -= mul * mat[i][k];
			}
			vec[j] -= vec[i] * mul;
		}
	}
	return vec;
}
int main() {
	int d;
	while (true) {
		scanf("%d", &d);
		if (!d) return 0;
		auto a = new ld[d + 3];
		for (int i = 0; i < d + 3; i++) {
			scanf("%Lf", &a[i]);
		}
		int const matrix_size = d + 1;
		ld min_dist = 200;
		int idx = -1;
		for (int i = 0; i < d + 3; i++) {
			auto mat = make_mat(matrix_size, i);
			auto res = calc(mat, a, i, matrix_size);
			int const compare = (i == d + 2 ? d + 1 : d + 2);
			/*printf("i = %d:\n", i);
			for (int i = 0; i < matrix_size; i++) {
				for (int j = 0; j < matrix_size; j++) {
					printf("%Lf ", mat[i][j]);
				} printf("\n");
			} printf("\n");*/
			ld mult = 1;
			ld sum = 0;
			for (int j = 0; j <= d; j++) {
				sum += mult * res[j];
				mult *= compare;
			}
			//printf("%Lf %Lf\n%Lf\n", sum, a[compare], fabsl(sum - a[compare]));
			if (idx == -1 || min_dist > fabsl(sum - a[compare])) {
				min_dist = fabsl(sum - a[compare]);
				idx = i;
			}
			for (int j = 0; j < matrix_size; j++) delete[] mat[j];
			delete[] mat;
			delete[] res;
		}
		printf("%d\n", idx);
		delete[] a;
	}
}