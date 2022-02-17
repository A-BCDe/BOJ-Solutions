#include <cmath>
#include <iostream>
#include <numeric>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
using ll = long long;
using point = pair<ll, ll>;
vector<ll> prime_init(int n) {
	vector<ll> primes;
	auto visited = new bool[n + 1]();
	int i;
	for(i = 2; i * i <= n; i++) {
		if(!visited[i]) {
			primes.push_back(i);
			for(int j = (i << 1); j * j <= n; j += i) {
				visited[j] = true;
			}
		}
	}
	for(; i <= n; i++) {
		if(!visited[i]) primes.push_back(i);
	}
	delete[] visited;
	return primes;
}
inline bool prime(vector<ll> const &primes, ll val) {
	auto const p = lower_bound(primes.begin(), primes.end(), val);
	return p != primes.end() && *p == val;
}
int dist(point const &x, point const &y) {
	auto const a = x.first - y.first;
	auto const b = x.second - y.second;
	return (int)floor(sqrt((double)(a * a + b * b)));
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	vector<point> points;
	vector<ll> primes = prime_init(9000);
	int n;
	points.resize(2);
	cin >> points[0].first >> points[0].second >> points[1].first >> points[1].second >> n;
	auto v = new vector<pair<int, int>>[n + 2];
	int d = dist(points[0], points[1]);
	if(prime(primes, d)) {
		v[0].emplace_back(-d, 1);
		v[1].emplace_back(-d, 0);
	}
	while(n--) {
		point x;
		cin >> x.first >> x.second;
		for(int i = 0; i < points.size(); i++) {
			d = dist(points[i], x);
			if(prime(primes, d)) {
				v[i].emplace_back(-d, points.size());
				v[points.size()].emplace_back(-d, i);
			}
		}
		points.emplace_back(move(x));
	}
	priority_queue<pair<int, int>> pq;
	pq.push({ 0, 0 });
	auto visited = new bool[points.size()]();
	while(!pq.empty()) {
		auto const now = pq.top(); pq.pop();
		if(visited[now.second]) continue;
		if(now.second == 1) {
			cout << -now.first;
			goto END;
		}
		visited[now.second] = true;
		for(auto const &next : v[now.second]) {
			if(visited[next.second]) continue;
			pq.push({ now.first + next.first, next.second });
		}
	}
	cout << -1;
END:delete[] visited;
	delete[] v;
}