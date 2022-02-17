#include <iostream>
using namespace std;
using ll = long long;
constexpr ll M = 1000;
ll** mul(ll n, ll** A, ll** B) {
	auto res = new ll * [n];
	for (int i = 0; i < n; i++) {
		res[i] = new ll[n]();
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for(int k = 0; k < n; k++) {
				res[i][j] = (res[i][j] + A[i][k] * B[k][j]) % M;
			}
		}
	}
	return res;
}
ll** power(ll n, ll** A, ll b) {
	if (!b) {
		auto res = new ll * [n];
		for (int i = 0; i < n; i++) {
			res[i] = new ll[n]();
		}
		for (int i = 0; i < n; i++) {
			res[i][i] = 1;
		}
		return res;
	}
	if (b == 1) {
		auto res = new ll * [n];
		for (int i = 0; i < n; i++) {
			res[i] = new ll[n];
			for (int j = 0; j < n; j++) {
				res[i][j] = A[i][j];
			}
		}
		return res;
	}
	auto B = power(n, A, b >> 1);
	auto C = mul(n, B, B);
	delete[] B;
	B = power(n, A, b & 1);
	auto res = mul(n, C, B);
	delete[] B;
	delete[] C;
	return res;
}
int main() {
	ll n, b;
	cin >> n >> b;
	auto A = new ll* [n];
	for (int i = 0; i < n; i++) {
		A[i] = new ll[n];
		for (int j = 0; j < n; j++) {
			cin >> A[i][j];
		}
	}
	auto res = power(n, A, b);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << res[i][j] % M << ' ';
		} cout << '\n';
	}
	delete[] A;
	delete[] res;
}