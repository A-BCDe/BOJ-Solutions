#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
constexpr ll M = 1000000007;
inline vector<ll> make_primes() {
	vector<ll> primes;
	vector<bool> visited(100000);
	for(ll i = 2; i * i <= 2000000000; i++) {
		if(!visited[i]) {
			primes.push_back(i);
			for(ll j = (i << 1); j < 100000; j += i) visited[j] = true;
		}
	}
	return primes;
}
inline ll phi(vector<ll> const &primes, ll x) {
	ll res = x;
	for(auto const p : primes) {
		if(p * p > x) break;
		bool flag = false;
		while(x % p == 0) { x /= p; flag = true; }
		if(flag) {
			res /= p;
			res *= p - 1;
		}
	}
	if(x > 1) {
		res /= x;
		res *= x - 1;
	}
	return res;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	auto const primes = make_primes();
	int t; cin >> t; while(t--) {
		int n; cin >> n;
		ll res = 1;
		while(n--) {
			ll x; cin >> x;
			ll p = phi(primes, x);
			res = (res * p) % M;
		}
		cout << res << '\n';
	}
}