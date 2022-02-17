#include <iostream>
#include <string>
#include <utility>
using namespace std;
int main() {
	int n, m;
	cin >> n >> m;
	string s, t;
	cin >> s >> t;
	auto a = new pair<int, int>* [n + 1];
	int max = 0;
	for (int i = n; i >= 0; i--) {
		a[i] = new pair<int, int>[m + 1](); // I 시작, O 시작
		for (int j = m; j >= 0; j--) {
			if (i == n && j == m) {
				a[i][j].first = a[i][j].second = 0;
				continue;
			}
			if (i < n) {
				if (s[i] == 'I') a[i][j].first = a[i + 1][j].second + 1;
				if (s[i] == 'O' && a[i + 1][j].first) a[i][j].second = a[i + 1][j].first + 1;
			}
			if (j < m) {
				if (t[j] == 'I' && a[i][j].first < a[i][j + 1].second + 1) a[i][j].first = a[i][j + 1].second + 1;
				if (t[j] == 'O' && a[i][j + 1].first && a[i][j].second < a[i][j + 1].first + 1) a[i][j].second = a[i][j + 1].first + 1;
			}
			if (max < a[i][j].first) max = a[i][j].first;
		}
	}/*
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%d ", a[i][j].first);
		}
		printf("\n");
	}
	*/
	printf("%d", max);
}