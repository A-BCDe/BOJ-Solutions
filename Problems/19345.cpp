#include <iostream>
#include <set>
#include <utility>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, m;
	cin >> n;
	auto a = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cin >> m;
	auto b = new int[m + 1];
	for (int i = 1; i <= m; i++) {
		cin >> b[i];
	}
	auto arr = new pair<pair<int, int>, int>* [n];
	int max = 1;
	for (int i = 0; i < n; i++) {
		arr[i] = new pair<pair<int, int>, int>[n](); // a[i] > a[j], a[i] < a[j], bidx
		pair<pair<int, int>, pair<int, int>> kp;
		for (int j = 0; j < i; j++) {
			arr[j][i];
		}
		for (int j = i + 1; j < n; j++) {
		}
	}
	cout << max;
}