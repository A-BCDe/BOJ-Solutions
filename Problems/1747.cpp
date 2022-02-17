#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
bool f(int a) {
	vector<int> v;
	while (a) {
		v.push_back(a % 10);
		a /= 10;
	}
	for (int i = 0; i < v.size() / 2; i++) {
		if (v[i] != v[v.size() - i - 1]) return false;
	}
	return true;
}
void prime(vector<int>& v) {
	auto b = new bool[2000000]();
	for (int i = 2; i < 2000000; i++) {
		if (!b[i]) {
			v.push_back(i);
			for (int j = i; j < 2000000; j += i) {
				b[j] = true;
			}
		}
	}
	delete[] b;
}
int main() {
	int n;
	scanf("%d", &n);
	vector<int> v;
	prime(v);
	for (auto it = lower_bound(v.begin(), v.end(), n); it != v.end(); ++it) {
		if (f(*it)) {
			printf("%d", *it);
			return 0;
		}
	}
}