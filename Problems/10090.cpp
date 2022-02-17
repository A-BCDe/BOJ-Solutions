#include <iostream>
using ll = long long;
using namespace std;
ll f(ll* a, ll l, ll r) { // [l, r)
	if (l + 1 >= r) return 0;
	auto const m = (l + r) / 2;
	auto const x = f(a, l, m); // [l, m), sorted
	auto const y = f(a, m, r); // [m, r), sorted
	int lit = 0, rit = 0;
	auto arr = new ll[r - l];
	ll cnt = x + y;
	while (lit < m - l || rit < r - m) {
		if (rit == r - m) {
			//printf("#1: l = %lld, r = %lld, lit = %d, rit = %d\n", l, r, lit, rit);
			arr[lit + rit] = a[l + lit];
			lit++;
			//printf("cnt = %lld\n", cnt);
			continue;
		}
		if (lit == m - l) {
			//printf("#2: l = %lld, r = %lld, lit = %d, rit = %d\n", l, r, lit, rit);
			arr[lit + rit] = a[m + rit];
			rit++;
			//printf("cnt = %lld\n", cnt);
			continue;
		}
		if (a[l + lit] > a[m + rit]) {
			//printf("#3: l = %lld, r = %lld, lit = %d, rit = %d\n", l, r, lit, rit);
			cnt += m - l - lit;
			arr[lit + rit] = a[m + rit];
			rit++;
			//printf("cnt = %lld\n", cnt);
			continue;
		}
		//printf("#4: l = %lld, r = %lld, lit = %d, rit = %d\n", l, r, lit, rit);
		arr[lit + rit] = a[l + lit];
		lit++;
		//printf("cnt = %lld\n", cnt);
	}
	for (int i = 0; i < r - l; i++) {
		a[l + i] = arr[i];
	}
	delete[] arr;
	return cnt;
}
int main() {
	int n;
	cin >> n;
	auto a = new ll[n];
	for (int i = 0; i < n; i++) {
		scanf("%lld", &a[i]);
	}
	printf("%lld", f(a, 0, n));
}