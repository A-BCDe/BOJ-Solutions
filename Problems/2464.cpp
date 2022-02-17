#include <algorithm>
#include <cassert>
#include <stdio.h>
#include <vector>
using namespace std;
using ll = long long;
void print(vector<int> const& v) {
	ll n = 0;
	for (int i = v.size() - 1; i >= 0; i--) {
		n <<= 1;
		n += v[i];
	}
	printf("%lld ", n);
}
int main() {
	ll n;
	scanf("%lld", &n);
	vector<int> v, u;
	while (n) {
		v.push_back(n & 1);
		n >>= 1;
	} u = v;
	u.push_back(0);
	// 1 -> 10 -> 100 -> 1000
	// 11 -> 101 -> 110 -> 1001 -> 1010 -> 1100 -> 10001
	// 111 -> 1011 -> 1101 -> 1110 -> 10011 -> 10101 -> 10110 -> 11001 -> 11010 -> 11100 -> 100011
	// 1111 -> 10111 -> 11011 -> 11101 -> 11110 -> 100111 -> 101011 -> 101101 -> 101110 -> 110011 -> 110101 -> 110110 -> 111001 -> 111010 -> 111100 -> 1000111
	int idx = 0;
	while (idx < u.size() && !u[idx]) idx++; int zero = idx;
	while (idx < u.size() && u[idx]) idx++; int one = idx - zero;
	u[idx] = 1; idx--;
	for (int i = 0; i <= zero; i++) u[idx - i] = 0;
	idx -= zero;
	while (idx--) u[idx] = 1;
	idx = 0;
	while (idx < v.size() && v[idx]) idx++; one = idx;
	while (idx < v.size() && !v[idx]) idx++; zero = idx - one;
	if (!zero) printf("0 ");
	else {
		v[zero + one] = 0;
		//for (int i = 0; i < v.size(); i++) printf("%d ", v[i]); printf("\n");
		for (int i = 1; i <= one + 1; i++) v[zero + one - i] = 1;
		//for (int i = 0; i < v.size(); i++) printf("%d ", v[i]); printf("\n");
		for (int i = 0; i < zero - 1; i++) v[i] = 0;
		//for (int i = 0; i < v.size(); i++) printf("%d ", v[i]); printf("\n");
		print(v);
	}
	print(u);
}