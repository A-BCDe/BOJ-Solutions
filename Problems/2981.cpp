#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int f(int a) { return a > 0 ? a : -a; }
int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}
int main() {
	int n;
	scanf("%d", &n);
	vector<int> v;
	vector<int> sub;
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		v.push_back(x);
		for (int j = 0; j < i; j++) {
			sub.push_back(f(v[i] - v[j]));
		}
	}
	sort(sub.begin(), sub.end());
	int g = sub[sub.size() - 1];
	for (int i = 0; i < sub.size() - 1; i++) {
		g = gcd(sub[i], g);
	}
	vector<int> a;
	for (int i = 1; i * i <= g; i++) {
		if (g % i == 0) {
			a.push_back(i);
			if (g != i * i) {
				a.push_back(g / i);
			}
		}
	}
	sort(a.begin(), a.end());
	for (int i = 1; i < a.size(); i++) {
		printf("%d ", a[i]);
	}
}