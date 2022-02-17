#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
int main() {
	int n;
	std::cin >> n;
	auto a = new int[n];
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	std::sort(a, a + n);
	std::vector<std::pair<int, int>> v;
	v.emplace_back(a[0], 1);
	for(int i = 1; i < n; i++) {
		int j = 0;
		for(; j < v.size(); j++) {
			if(v[j].second > a[i]) continue;
			v[j].first = a[i];
			v[j].second++;
			break;
		}
		if(j == v.size()) v.emplace_back(a[i], 1);
	}
	std::cout << v.size();
}