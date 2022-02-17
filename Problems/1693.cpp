#include <iostream>
#include <utility>
#include <vector>
using namespace std;
using ll = long long;
pair<pair<int, ll>, pair<int, ll>> f(vector<int> const *v, int cur, int prev) {
	vector<pair<pair<int, ll>, pair<int, ll>>> vec;
	int max = 0;
	for(int next : v[cur]) {
		if(next == prev) continue;
		vec.emplace_back(f(v, next, cur));
		if(vec.back().first.first > max) max = vec.back().first.first;
		if(vec.back().second.first > max) max = vec.back().second.first;
	}
	if(!max) return { { 1, 1 }, { 2, 2 } };
	ll res1 = 2000000000000000000, res2 = 2000000000000000000;
	int resi1 = 0, resi2 = 0;
	for(int i = 1; i <= max + 1; i++) {
		ll val = i;
		for(auto const &now : vec) {
			if(now.first.first == i) val += now.second.second;
			else val += now.first.second;
		}
		if(res1 >= val) {
			res2 = res1;
			res1 = val;
			resi2 = resi1;
			resi1 = i;
		}
		else if(res2 >= val) {
			res2 = val;
			resi2 = i;
		}
	}
	return { { resi1, res1 }, { resi2, res2 } };
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n;
	cin >> n;
	if(n == 1) {
		cout << 1;
		return 0;
	}
	auto v = new vector<int>[n + 1];
	for(int i = 1; i < n; i++) {
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	auto res = f(v, 1, 0);
	cout << res.first.second;
}