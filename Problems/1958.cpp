#include <iostream>
#include <string>
using namespace std;
int main() {
	string a, b, c;
	cin >> a >> b >> c;
	auto arr = new int**[a.size() + 1];
	for (int i = 0; i <= a.size(); i++) {
		arr[i] = new int* [b.size() + 1];
		for (int j = 0; j <= b.size(); j++) {
			arr[i][j] = new int[c.size() + 1]();
		}
	}
	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < b.size(); j++) {
			for (int k = 0; k < c.size(); k++) {
				if (a[i] == b[j] && b[j] == c[k]) {
					arr[i + 1][j + 1][k + 1] = arr[i][j][k] + 1;
				}
				else {
					int x = arr[i + 1][j + 1][k];
					if (x < arr[i + 1][j][k + 1]) x = arr[i + 1][j][k + 1];
					if (x < arr[i][j + 1][k + 1]) x = arr[i][j + 1][k + 1];
					arr[i + 1][j + 1][k + 1] = x;
				}
			}
		}
	}
	printf("%d", arr[a.size()][b.size()][c.size()]);
	for (int i = 0; i <= a.size(); i++) {
		for (int j = 0; j <= b.size(); j++) {
			delete[] arr[i][j];
		}
		delete[] arr[i];
	}
	delete[] arr;
}