#include <iostream>
#include <vector>
using namespace std;
using ll = unsigned long long;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	ll q, m;
	cin >> q >> m;
	vector<ll> v;
	v.push_back(0);
	v.push_back(1);
	do {
		auto const size = v.size();
		v.push_back((v[size - 1] + v[size - 2]) % m);
	} while (v[v.size() - 1] != 1 || v[v.size() - 2] != 0);
	v.pop_back(); v.pop_back();
	vector<ll> hit;
	for (auto now : v) {
		if (!now) {
			hit.push_back(0);
			continue;
		}
		vector<ll> tmp;
		while (now) {
			tmp.push_back(now % 10);
			now /= 10;
		}
		while (!tmp.empty()) {
			hit.push_back(tmp.back());
			tmp.pop_back();
		}
	}
	while (q--) {
		ll n; cin >> n;
		cout << hit[n % hit.size()] << '\n';
	}
}