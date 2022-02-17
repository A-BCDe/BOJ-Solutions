#include <iostream>
#include <queue>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int t; cin >> t; while(t--) {
		int n; cin >> n;
		priority_queue<long long, std::vector<long long>, std::greater<>> pq;
		for(int i = 0; i < n; i++) {
			int x; cin >> x; pq.push(x);
		}
		long long res = 0;
		while(pq.size() > 1) {
			auto const a = pq.top(); pq.pop();
			auto const b = pq.top(); pq.pop();
			res += a + b;
			pq.push(a + b);
		}
		cout << res << '\n';
	}
}