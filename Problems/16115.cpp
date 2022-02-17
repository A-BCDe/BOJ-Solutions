#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <vector>
using namespace std;
using ll = long long;
constexpr long double PI = 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342117067982148086513282306647093844609550582231725359408128481;
struct Point { ll x, y; };
inline ll ccw(Point const &a, Point const &b, Point const &c) {
	return a.x * b.y + b.x * c.y + c.x * a.y - a.y * b.x - b.y * c.x - c.y * a.x;
}
int main() {
	int n; scanf("%d", &n);
	Point *pa = (Point*)malloc(sizeof(Point) * n);
	vector<Point> v; ll dist = 0;
	for(int i = 0; i < n; i++) {
		scanf("%lld%lld", &pa[i].x, &pa[i].y);
		ll d = pa[i].x * pa[i].x + pa[i].y * pa[i].y;
		if(dist == d) v.push_back(pa[i]);
		else if(v.empty() || dist < d) {
			dist = d;
			v.clear(); v.push_back(pa[i]);
		}
	}
	if(v.size() == 1) {
		printf("360");
		free(pa);
		return 0;
	}
	v.push_back(v[0]);
	long double rad = 0;
	for(int i = 1; i < v.size(); i++) {
		ll const num = v[i].y * v[i - 1].x - v[i - 1].y * v[i].x;
		ll const den = v[i].x * v[i - 1].x + v[i].y * v[i - 1].y;
		ll const CCW = ccw(v[i], { 0, 0 }, v[i - 1]);
		long double cur;
		if(den == 0) {
			if(CCW > 0) cur = PI / 2;
			else cur = PI / 2 * 3;
		} else if(num == 0) {
			cur = PI;
		} else if((num > 0) ^ (den > 0)) { // tangent negative
			if(CCW > 0) cur = PI + atanl((long double)num / den);
			else cur = 2 * PI + atanl((long double)num / den);
		} else { // tangent positive
			if(CCW > 0) cur = atanl((long double)num / den);
			else cur = PI + atanl((long double)num / den);
		}
		if(rad < cur) rad = cur;
	}
	printf("%.15Lf", rad * 180 / PI);
	free(pa);
}