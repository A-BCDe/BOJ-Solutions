#include <iostream>
#include <cmath>
using namespace std;
using T = float;
T _abs(T x) { return x > 0 ? x : -x; }
T triangle(T a1, T a2, T b1, T b2, T c1, T c2) {
	return _abs(a2 * b1 + b2 * c1 + c2 * a1 - a1 * b2 - b1 * c2 - c1 * a2) / 2;
}

void line(T p1, T p2, T q1, T q2, T& a, T& b, T& c) {
	a = p2 - q2;
	b = q1 - p1;
	c = p1 * q2 - p2 * q1;
}
void intersection(T a1, T b1, T c1, T a2, T b2, T c2, T& x, T& y) {
	x = (c1 * b2 - b1 * c2) / (b1 * a2 - a1 * b2);
	y = (c1 * a2 - a1 * c2) / (a1 * b2 - a2 * b1);
}

void midpoint(T p1, T p2, T q1, T q2, T& x, T& y) {
	x = (p1 + q1) / 2;
	y = (p2 + q2) / 2;
}

T _sqrt(T x) {
	T l = 0, r = x < 1 ? 1 : x;
	while (r - l >= 0.000001) {
		auto m = (l + r) / 2;
		if (m * m == x) return m;
		if (m * m < x) {
			l = m;
		}
		else r = m;
	}
	return r;
}

T dist(T p1, T p2, T q1, T q2) {
	T const x = q1 - p1;
	T const y = q2 - p2;
	return sqrt(x * x + y * y);
}

unsigned long long up(T x) {
	unsigned long long n = x + 0.5;
	if (n > x) return n;
	if (n < x) return n + 1;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		T a1 = 0, a2 = 0, b2 = 0;
		T b1, c1, c2, d1, d2;
		cin >> b1 >> c1 >> c2 >> d1 >> d2;
		
		T aa1, aa2, bb1, bb2, cc1, cc2, dd1, dd2;
		midpoint(b1, b2, c1, c2, aa1, aa2);
		midpoint(c1, c2, d1, d2, bb1, bb2);
		midpoint(d1, d2, a1, a2, cc1, cc2);
		midpoint(a1, a2, b1, b2, dd1, dd2);
		
		T Aa, Ab, Ac, Ba, Bb, Bc, Ca, Cb, Cc, Da, Db, Dc;
		line(a1, a2, aa1, aa2, Aa, Ab, Ac);
		line(b1, b2, bb1, bb2, Ba, Bb, Bc);
		line(c1, c2, cc1, cc2, Ca, Cb, Cc);
		line(d1, d2, dd1, dd2, Da, Db, Dc);
		
		T aaa1, aaa2, bbb1, bbb2, ccc1, ccc2, ddd1, ddd2;
		intersection(Aa, Ab, Ac, Ba, Bb, Bc, aaa1, aaa2);
		intersection(Ba, Bb, Bc, Ca, Cb, Cc, bbb1, bbb2);
		intersection(Ca, Cb, Cc, Da, Db, Dc, ccc1, ccc2);
		intersection(Da, Db, Dc, Aa, Ab, Ac, ddd1, ddd2);

		cout << fixed;
		cout.precision(3);
		
		cout << triangle(a1, a2, b1, b2, aaa1, aaa2) << ' ';
		cout << triangle(b1, b2, c1, c2, bbb1, bbb2) << ' ';
		cout << triangle(c1, c2, d1, d2, ccc1, ccc2) << ' ';
		cout << triangle(d1, d2, a1, a2, ddd1, ddd2) << ' ';
		cout << up(dist(aaa1, aaa2, bbb1, bbb2) + dist(bbb1, bbb2, ccc1, ccc2) + dist(ccc1, ccc2, ddd1, ddd2)+ dist(ddd1, ddd2, aaa1, aaa2)) << '\n';
	}
}