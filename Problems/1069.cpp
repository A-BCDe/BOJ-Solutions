#include <iostream>
#include <math.h>
using namespace std;
int main() {
	int x, y, d, t;
	cout.precision(13);
	scanf("%d%d%d%d", &x, &y, &d, &t);
	long double dist = sqrt((long double)(x * x + y * y));
	cout << dist << std::endl;
	if (d <= t) {
		cout << dist;
		return 0;
	}
	int k = 0;
	while (!(d * k <= dist && d * (k + 1) > dist)) k++;
	if (d * k == dist) {
		printf("%d", k * t);
		return 0;
	}
	auto one = k * t - k * d + dist;
	auto two = k * t + t + (k + 1) * d - dist;
	auto three = k * t + 2 * t;
	auto four = (k + 2) * t;
	auto min = one;
	if (min > two) min = two;
	if (min > three) min = three;
	if (min > four) min = four;
	cout << min;
}