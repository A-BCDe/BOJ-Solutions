#include <stdio.h>
#include <algorithm>
#include <utility>
#include <map>
using namespace std;
int main() {
	int n, m, q;
	scanf("%d%d%d", &n, &m, &q);
	auto a = new pair<int, int>[q];
	for (int i = 0; i < q; i++) {
		scanf("%d%d", &a[i].first, &a[i].second);
	}
	sort(a, a + q, [](pair<int, int> const& a, pair<int, int> const& b) {
		return (a.second - a.first < b.second - b.first) || (a.second - a.first == b.second - b.first && a.first < b.first);
	});
	auto arr = new char[m]();
	for (int i = 0; i < m; i++) {
		arr[i] = (i % (2 * n) / 2) + 'a';
	}
	for (int i = 0; i < q; i++) {
		map<char, int> mp;
		for (int j = a[i].first - 1; j < a[i].second; j++) {
			mp[arr[j]]++;
		}
		for (auto it = mp.begin(); it != mp.end(); ++it) {
			printf("%c: %d\n", it->first, it->second);
		}
		printf("\n");
	}
	for (int i = 0; i < m; i++) {
		printf("%c", arr[i]);
	}
	delete[] arr;
	delete[] a;
}