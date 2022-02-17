#include <iostream>
#include <vector>
using namespace std;
void flip(int* a, int l) {
	for (int i = 0; i < l / 2; i++) {
		int tmp = a[i];
		a[i] = a[l - i - 1];
		a[l - i - 1] = tmp;
	}
}
int main() {
	int tt;
	scanf("%d", &tt);
	while (tt--) {
		int n;
		scanf("%d", &n);
		auto a = new int[n];
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}
		vector<int> v;
		for (int i = n; i > 0; i--) {
			int maxi = 0;
			for (int j = 1; j < i; j++) {
				if (a[maxi] < a[j]) maxi = j;
			}
			if (maxi == i - 1) continue;
			if (maxi > 0) {
				v.push_back(maxi + 1);
				flip(a, maxi + 1);
			}
			v.push_back(i);
			flip(a, i);
		}
		cout << v.size();
		for (int i = 0; i < v.size(); i++) {
			cout << ' ' << v[i];
		}
		cout << endl;
	}
}