#include <iostream>
using ll = long long;
using namespace std;
constexpr ll M = 1000000007;
void mul(ll const A[4], ll const B[4], ll C[4]) {
	C[0] = ((A[0] * B[0]) % M + (A[1] * B[2]) % M) % M;
	C[1] = ((A[0] * B[1]) % M + (A[1] * B[3]) % M) % M;
	C[2] = ((A[2] * B[0]) % M + (A[3] * B[2]) % M) % M;
	C[3] = ((A[2] * B[1]) % M + (A[3] * B[3]) % M) % M;
}
void power(ll A[4], ll n) {
	if (n == 0) {
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
	mul(B, C, A);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	ll A[4], n;
	cin >> n;
	power(A, n);
	cout << A[1];
}