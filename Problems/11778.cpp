#include <stdio.h>
using ll = long long;
constexpr ll p = 1000000007;
ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}
void mul(ll const A[4], ll const B[4], ll C[4]) {
	C[0] = ((A[0] * B[0]) % p + (A[1] * B[2]) % p) % p;
	C[1] = ((A[0] * B[1]) % p + (A[1] * B[3]) % p) % p;
	C[2] = ((A[2] * B[0]) % p + (A[3] * B[2]) % p) % p;
	C[3] = ((A[2] * B[1]) % p + (A[3] * B[3]) % p) % p;
}
void fib(ll A[4], ll g) {
	if (g == 0) {
		A[0] = A[3] = 1;
		A[1] = A[2] = 0;
		return;
	}
	if (g == 1) {
		A[0] = A[1] = A[2] = 1;
		A[3] = 0;
		return;
	}
	ll B[4];
	fib(B, g / 2);
	ll C[4];
	mul(B, B, C);
	ll D[4];
	fib(D, g % 2);
	mul(C, D, B);
	for (int i = 0; i < 4; i++) {
		A[i] = B[i];
	}
	return;
}
int main() {
	ll n, m;
	scanf("%lld%lld", &n, &m);
	ll const g = gcd(n, m);
	ll A[4];
	fib(A, g);
	printf("%lld", A[2]);
}