#include <stdio.h>
constexpr int c = 1000000;
using ll = long long;
void mul(ll const* A, ll const* B, ll* C) {
	C[0] = ((A[0] * B[0]) % c + (A[1] * B[2]) % c) % c;
	C[1] = ((A[0] * B[1]) % c + (A[1] * B[3]) % c) % c;
	C[2] = ((A[2] * B[0]) % c + (A[3] * B[2]) % c) % c;
	C[3] = ((A[2] * B[1]) % c + (A[3] * B[3]) % c) % c;
}
void power(ll* A, long long n) {
	if (n == 0) {
		A[0] = A[3] = 1;
		A[1] = A[2] = 0;
		return;
	}
	if (n == 1) return;
	ll B[4];
	for (int i = 0; i < 4; i++) {
		B[i] = A[i];
	}
	power(B, n / 2);
	ll C[4];
	ll D[4];
	power(A, n % 2);
	mul(B, B, C);
	mul(C, A, D);
	for (int i = 0; i < 4; i++) {
		A[i] = D[i];
	}
}
int main() {
	ll A[4] = { 1, 1, 1, 0 };
	// F_(n+2) = F_(n+1) + F_n
	// F_(n+1) = F_(n+1)
	// v_n = A^n * v_0
	// v_n = [F_(n+1) F_n]
	// A = [[1 1] [1 0]]
	ll n;
	scanf("%lld", &n);
	power(A, n);
	printf("%lld", A[2]);
}