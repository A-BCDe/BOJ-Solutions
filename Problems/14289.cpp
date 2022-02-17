#include <stdio.h>
#include <algorithm>
using std::copy;
using ll = long long;
constexpr ll M = 1000000007;
void del(ll** A, ll n) {
	for (int i = 1; i <= n; i++) delete[] A[i];
	delete[] A;
}
ll** mul(ll const* const* A, ll const* const* B, ll n) {
	auto res = new ll*[n + 1];
	for (int i = 1; i <= n; i++) {
		res[i] = new ll[n + 1]();
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				res[i][j] = (((A[i][k] * B[k][j]) % M) + res[i][j]) % M;
			}
		}
	}
	return res;
}
ll** power(ll const* const* A, ll n, ll d) {
	if (!d) {
		auto res = new ll*[n + 1];
		for (int i = 1; i <= n; i++) {
			res[i] = new ll[n + 1]();
			res[i][i] = 1;
		}
		return res;
	}
	if (d == 1) {
		auto res = new ll*[n + 1];
		for (int i = 1; i <= n; i++) {
			res[i] = new ll[n + 1];
			copy(A[i] + 1, A[i] + n + 1, res[i] + 1);
		}
		return res;
	}
	auto B = power(A, n, d >> 1);
	auto C = mul(B, B, n);
	del(B, n);
	B = power(A, n, d & 1);
	auto res = mul(B, C, n);
	del(B, n);
	del(C, n);
	return res;
}
int main() {
	ll n, m;
	scanf("%lld%lld", &n, &m);
	auto A = new ll* [n + 1];
	for (int i = 1; i <= n; i++) {
		A[i] = new ll[n + 1]();
	}
	while (m--) {
		int x, y;
		scanf("%d%d", &x, &y);
		A[x][y] = A[y][x] = 1;
	}
	ll d;
	scanf("%lld", &d);
	auto res = power(A, n, d);
	printf("%lld", res[1][1] % M);
	del(res, n);
	del(A, n);
}