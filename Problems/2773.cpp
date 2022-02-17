#include <stdio.h>
int main() {
	int tt;
	scanf("%d", &tt);
	while (tt--) {
		double ax, ay, bx, by, cx, cy;
		scanf("%lf%lf%lf%lf%lf%lf", &ax, &ay, &bx, &by, &cx, &cy);
		ax -= cx; ay -= cy;
		bx -= cx; by -= cy;
		double y = -(ax - bx) * (ax * bx + ay * by) / (ay * bx - ax * by);
		double x = -(ay - by) * (ay * by + ax * bx) / (ax * by - ay * bx);

		printf("%.4lf %.4lf\n", x + cx, y + cy);
	}
}