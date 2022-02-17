#include <stdio.h>
#include <vector>
using namespace std;
int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	auto a = new int[k];
	vector<int> p;
	for (int i = 0; i < k; i++) {
		scanf("%d", a + i);
	}
	int res = 0;
	for (int i = 0; i < k; i++) {
		bool flag = false;
		for (int j = 0; j < p.size(); j++) {
			if (p[j] == a[i]) {
				flag = true;
				break;
			}
		}
		if (flag) continue;
		if (p.size() < n) {
			p.push_back(a[i]);
			continue;
		}
		auto tmp = new int[n];
		for (int j = 0; j < n; j++) {
			tmp[j] = k;
			for (int l = i + 1; l < k; l++) {
				if (p[j] == a[l]) {
					tmp[j] = l;
					break;
				}
			}
		}
		int max = 0;
		for (int j = 1; j < n; j++) {
			if (tmp[j] > tmp[max]) max = j;
		}
		p[max] = a[i];
		res++;
		delete[] tmp;
	}
	printf("%d", res);
	delete[] a;
}