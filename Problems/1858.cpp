#include <algorithm>
#include <iostream>
#include <numeric>
#include <utility>
using namespace std;
using ll = long long;
pair<ll, ll> slope(pair<ll, ll> const &a, pair<ll, ll> const &b) {
	ll x = abs(a.first - b.first);
	ll y = abs(a.second - b.second);
	ll g = gcd(x, y);
	return { x / g, y / g };
}
ll comp(pair<ll, ll> const &m, pair<ll, ll> const &s) {
	// -1 : <, 0 : =, 1  : >
	// m.second / m.first ? s.second / s.first
	ll lhs = m.second * s.first;
	ll rhs = s.second * m.first;
	if(lhs == rhs) return 0;
	if(lhs < rhs) return -1;
	return 1;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	ll n;
	cin >> n;
	auto a = new pair<pair<ll, ll>, ll>[n];
	for(ll i = 0; i < n; i++) {
		cin >> a[i].first.first >> a[i].first.second;
		a[i].second = i + 1;
	}
	sort(a, a + n);
	auto m = make_pair<ll, ll>(0, 0);
	ll resx = -1, resy = -1;
	for(ll i = 1; i < n; i++) {
		auto x = a[i - 1], y = a[i];
		if(x.second > y.second) swap(x, y);
		auto const s = slope(x.first, y.first);
		auto const c = comp(m, s);
		if(m == make_pair<ll, ll>(0, 0) || c == -1) {
			resx = x.second, resy = y.second;
			m = s;
		}
		else if(!c) {
			// resx < resy, x.second < y.second
			if(resx > x.second || (res == x.second && )) {

			}
		}
	}
	cout << resx << ' ' << resy;
}