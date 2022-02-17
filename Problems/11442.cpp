#include <iostream>
using namespace std;
using ull = unsigned long long;
constexpr ull M = 1000000007;
void mul(ull const A[4], ull const B[4], ull C[4]) {
	C[0] = ((A[0] * B[0]) % M + (A[1] * B[2]) % M) % M;
	C[1] = ((A[0] * B[1]) % M + (A[1] * B[3]) % M) % M;
	C[2] = ((A[2] * B[0]) % M + (A[3] * B[2]) % M) % M;
	C[3] = ((A[2] * B[1]) % M + (A[3] * B[3]) % M) % M;
}
void power(ull A[4], ull n) {
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
	ull B[4], C[4];
	power(B, n >> 1);
	mul(B, B, C);
	power(B, n & 1);
	mul(C, B, A);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	ull n; cin >> n;
	if (n & 1) n++;
	ull A[4];
	power(A, n);
	cout << (A[2] % M);
}