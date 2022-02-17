#include <iostream>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
int main() {
	int n;
	cin >> n;
	auto a = new string[n];
	bool b[10] = {};
	long long c[10] = {};
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		b[a[i][0] - 'A'] = true;
		long long pw = 1;
		for (int j = a[i].size() - 1; j >= 0; j--) {
			c[a[i][j] - 'A'] += pw;
			pw *= 10;
		}
	}
	pair<pair<long long, int>, bool> p[10];
	for (int i = 0; i < 10; i++) {
		p[i].first.first = c[i];
		p[i].first.second = i;
		p[i].second = b[i];
	}
	printf("\n");
	sort(p, p + 10);
	for (int i = 0; i < 10; i++) {
		cout << p[i].first.first << ' ' << p[i].first.second << ' ' << p[i].second << endl;
	}

	bool flag = false;
	int min = 1;
	long long res = 0;
	for (int i = 0; i < 10; i++) {
		if (p[i].second || flag) {
			res += min * p[i].first.first;
			min++;
		}
		else {
			flag = true;
		}
	}
	cout << res;
	delete[] a;
}