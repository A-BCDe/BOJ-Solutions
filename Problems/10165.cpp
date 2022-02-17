#include <algorithm>
#include <iostream>
#include <utility>
using namespace std;
using ll = long long;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	ll n, m;
	cin >> n >> m;
	auto a = new pair<pair<ll, ll>, ll>[m << 1];
	for (ll i = 0; i < m; i++) {
		cin >> a[i << 1].first.first >> a[i << 1].first.second;
		if (a[i << 1].first.first < a[i << 1].first.second) {
			a[i << 1].first.first += n;
		}
		a[i << 1].first.second += n;
		a[i << 1].second = i;
		a[(i << 1) + 1] = a[i << 1];
		a[(i << 1) + 1].first.first += n;
		a[(i << 1) + 1].first.second += n;
	}
	sort(a, a + (m << 1), [](pair<pair<ll, ll>, ll> const& a, pair<pair<ll, ll>, ll> const& b) {
		return a.first.first < b.first.first || (a.first.first == b.first.first && a.first.second > b.first.second);
	});
	ll r = 0;
	auto visited = new bool[m]();
	for (ll i = 0; i < (m << 1); i++) {
		if (visited[a[i].second]) continue;
		if (r >= a[i].first.second) {
			visited[a[i].second] = true;
		}
		else r = a[i].first.second;
	}
	for (ll i = 0; i < m; i++) {
		if (!visited[i]) cout << i + 1 << ' ';
	}
	delete[] visited;
	delete[] a;
}