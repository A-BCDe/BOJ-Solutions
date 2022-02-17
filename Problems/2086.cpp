#include <iostream>
using ll = unsigned long long;
constexpr ll M = 1000000000;
void mul(ll const A[4], ll const B[4], ll C[4]) {
	C[0] = ((A[0] * B[0]) % M + (A[1] * B[2]) % M) % M;
	C[1] = ((A[0] * B[1]) % M + (A[1] * B[3]) % M) % M;
	C[2] = ((A[2] * B[0]) % M + (A[3] * B[2]) % M) % M;
	C[3] = ((A[2] * B[1]) % M + (A[3] * B[3]) % M) % M;
}
void power(ll A[4], ll n) {
	if (!n) {
		A[0] = A[3] = 1;
		A[1] = A[2] = 0;
		return;
	}
	if (n == 1) {
		A[0] = A[1] = A[2] = 1;
		A[3] = 0;
		return;
	}
	ll B[4], C[4];
	power(B, n >> 1);
	mul(B, B, C);
	power(B, n & 1);
	mul(C, B, A);
}
inline ll fib(ll n) {
	ll A[4];
	power(A, n);
	return A[2];
}
int main() {
	ll a, b;
	std::cin >> a >> b;
	std::cout << (fib(b + 2) + M - fib(a + 1)) % M;
}