#include <stdio.h>
long long power(int k) {
	if (k == 0) return 1;
	if (k == 1) return 10;
	auto const r = power(k / 2);
	return r * r * power(k % 2);
}
long long bigsum(long long k) {
	return 45 * power(k - 1) * k;
}
long long smallsum(int* a) {
	long long res = 0;
	for (int i = 9; i >= 0; i--) {
		res += a[i];
	}
	return res;
}
long long num(int* a) {
	long long res = 0;
	for (int i = 9; i >= 0; i--) {
		res *= 10; 
		res += a[i];
	}
	return res;
}
int main() {
	int l, u;
	scanf("%d%d", &l, &u);
	int a[10] = {};
	int b[10] = { 9, 9, 9, 9, 9, 9, 9, 9, 9, 9 };
	long long res;
	if (u == 2000000000) {
		b[9] = 2;
		res = bigsum(9) * 3 + 3000000000;
	}
	else if (u >= 1000000000) {
		b[9] = 1;
		res = bigsum(9) * 2 + 1000000000;
	}
	else {
		b[9] = 0;
		res = bigsum(9);
	}
	int k = 9;
	while (k) {
		long long const pow = power(k);
		int aa[10] = {};
		int bb[10] = {};
		for (int i = 9; i >= k; i--) {
			aa[i] = a[i];
			bb[i] = b[i];
		}
		while (!(num(a) <= l && num(a) + pow > l)) {
			res -= (smallsum(aa) * pow + bigsum(k));
			a[k]++; aa[k]++;
		}
		while (!(num(b) >= u && num(b) - pow < u)) {
			res -= (smallsum(bb) * pow + bigsum(k));
			b[k]--; bb[k]--;
		}
		k--;
	}
	while (num(a) != l) {
		res -= smallsum(a);
		a[0]++;
	}
	while (num(b) != u) {
		res -= smallsum(b);
		b[0]--;
	}
	printf("%lld", res);
}