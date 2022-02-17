#include <stdio.h>
#include <vector>
#include <map>
using namespace std;
void prime(int max, vector<int>& p) {
	auto b = new bool[max + 1]();
	for (int i = 2; i <= max; i++) {
		if (!b[i]) {
			p.push_back(i);
			for (int j = i; j <= max; j += i) {
				b[j] = true;
			}
		}
	}
}
int main() {
	int n;
	scanf("%d", &n);
	auto a = new int[n];
	int max = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		if (max < a[i]) max = a[i];
	}
	vector<int> p;
	prime(max, p);
	auto m = new int[p.size()]();
	for (int i = 0; i < n; i++) {
		int x = a[i];
		for (int j = 0; j < p.size() && x > 1; j++) {
			while (x % p[j] == 0) {
				m[j]++;
				x /= p[j];
			}
		}

	}
	delete[] m;
	delete[] a;
}