#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
void sum(vector<int> const& v, vector<int>& sumv, vector<int>& visited, int idx, int cnt) {
	if (idx == v.size()) {
		if (cnt) {
			int sum = 0;
			for (int i = 0; i < idx; i++) {
				if (visited[i]) sum += v[i];
			}
			sumv.push_back(sum);
		}
		return;
	}
	visited[idx] = false;
	sum(v, sumv, visited, idx + 1, cnt);
	visited[idx] = true;
	sum(v, sumv, visited, idx + 1, cnt + 1);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, s;
	cin >> n >> s;
	vector<int> u, v;
	for (int i = 0; i < n / 2; i++) {
		int x;
		cin >> x;
		u.push_back(x);
	}
	for (int i = n / 2; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}
	vector<int> sumu, sumv;
	vector<int> visited(u.size());
	sum(u, sumu, visited, 0, 0);
	visited.resize(v.size());
	fill(visited.begin(), visited.end(), false);
	sum(v, sumv, visited, 0, 0);
	sort(sumu.begin(), sumu.end());
	sort(sumv.begin(), sumv.end());
	ll res = 0;
	res += upper_bound(sumu.begin(), sumu.end(), s) - lower_bound(sumu.begin(), sumu.end(), s);
	res += upper_bound(sumv.begin(), sumv.end(), s) - lower_bound(sumv.begin(), sumv.end(), s);
	for (auto now : sumv) {
		res += upper_bound(sumu.begin(), sumu.end(), s - now) - lower_bound(sumu.begin(), sumu.end(), s - now);
	}
	cout << res;
}