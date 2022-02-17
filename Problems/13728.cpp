#include <numeric>
#include <stdio.h>
using namespace std;
using ll = long long;
constexpr ll M = 1000000007;
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
	power(B, n / 2);
	mul(B, B, C);
	power(B, n % 2);
	mul(C, B, A);
}
inline ll fib(int n) {
	ll A[4];
	power(A, n);
	return A[1];
}
int main() {
	int n;
	scanf("%d", &n);
	ll sum = 0;
	for (int i = 2; i < n + 2; i++) {
		sum = (sum + fib(gcd(i, n + 1))) % M;
	}
	printf("%lld", sum);
}