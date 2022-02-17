#include <iostream>
#include <queue>
using namespace std;
using ll = long long;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int k, n;
	cin >> k >> n;
	auto a = new ll[k];
	priority_queue<ll> pq;
	for (int i = 0; i < k; i++) {
		cin >> a[i];
		pq.push(-a[i]);
	} // 2 5 7
	for (int i = 0; i < n - 1; i++) {
		auto const now = -pq.top(); pq.pop();
		for (int i = k - 1; i >= 0; i--) {
			pq.push(-now * a[i]);
			if (now % a[i] == 0) break;
		}
	}
	cout << -pq.top();
	delete[] a;
}