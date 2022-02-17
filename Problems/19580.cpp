#include <iostream>
#include <algorithm>
#include <memory>
#include <map>
#include <utility>
using ll = long long;
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, m;
	cin >> n >> m;
	auto a = make_unique<pair<ll, ll>[]>(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i].second >> a[i].first;
	}
	sort(a.get(), a.get() + n);
	map<ll, int> store;
	for (int i = 0; i < m; i++) {
		ll x;
		int y;
		cin >> x >> y;
		store[x] += y;
	}
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		auto it = store.lower_bound(a[i].second);
		if (it == store.end()) continue;
		if (it->first > a[i].first) continue;
		if (--it->second == 0) store.erase(it);
		cnt++;
	}
	printf("%d", cnt);
}