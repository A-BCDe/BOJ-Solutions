#include <stdio.h>
#include <vector>
using namespace std;
void prime(int n, vector<int> &p) {
	auto b = new bool[n + 1]();
	for (int i = 2; i <= n; i++) {
		if (!b[i]) {
			p.push_back(i);
			for (int j = i; j <= n; j += i) {
				b[j] = true;
			}
		}
	}
	delete[] b;
}
int main() {
	vector<int> p;
	int n;
	scanf("%d", &n);
	prime(n, p);
	int l = 0, r = 0;
	int sum = 0;
	int res = 0;
	while (l < p.size()) {
		if (l == r) {
			sum += p[r++];
			continue;
		}
		if (sum == n) {
			res++;
			if (r < p.size()) sum += p[r++];
			else sum -= p[l++];
		}
		else if (sum < n) {
			if (r < p.size()) {
				sum += p[r++];
			}
			else sum -= p[l++];
		}
		else {
			sum -= p[l++];
		}
	}
	printf("%d", res);
}