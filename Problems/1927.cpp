#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using ll = long long;
struct comp {
	bool operator()(ll a, ll b) {
		return f(a) > f(b) || (f(a) == f(b) && a > b);
	}
	static ll f(ll a) { return a < 0 ? -a : a; }
};
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin >> n;
	priority_queue<ll, vector<ll>, comp> pq;
	while (n--) {
		ll x;
		cin >> x;
		if (x == 0) {
			if (pq.empty()) cout << "0\n";
			else {
				cout << pq.top() << '\n'; pq.pop();
			}
		}
		else pq.push(x);
	}
}