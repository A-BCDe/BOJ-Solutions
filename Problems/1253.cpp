#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;
using ll = long long;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin >> n;
	vector<ll> v;
	vector<pair<ll, pair<int, int>>> sum;
	for (int i = 0; i < n; i++) {
		ll x; cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			sum.emplace_back(v[i] + v[j], make_pair(i, j));
		}
	}
	sort(sum.begin(), sum.end());
	ll res = 0;
	for (int i = 0; i < n; i++) {
		auto it = lower_bound(sum.begin(), sum.end(), make_pair(v[i], make_pair(0, 0)));
		while (it != sum.end() && it->first == v[i] && !(it->second.first != i && it->second.second != i)) it++;
		res += !(it == sum.end() || it->first != v[i] || it->second.first == i || it->second.second == i);
	}
	cout << res;
}