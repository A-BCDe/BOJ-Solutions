#include <algorithm>
#include <iostream>
using namespace std;
using ll = long long;
ll f(int i) {
	if(!i) return 1;
	return i * f(i - 1);
}
int main() {
	int n, x;
	cin >> n >> x;
	auto used = new bool[n + 1]();
	if(x == 1) {
		ll m; cin >> m;
		for(int i = n - 1; i >= 0; i--) {
			ll const fact = f(i);
			int j = 1, cnt = 0;
			for(; j <= n; j++) {
				if(used[j]) continue;
				if(cnt * fact < m && (cnt + 1) * fact >= m) break;
				cnt++;
			}
			m -= cnt * fact;
			cout << j << ' ';
			used[j] = true;
		}
		return 0;
	}
	ll m = 1;
	for(int i = n - 1; i >= 0; i--) {
		int y; cin >> y;
		ll const fact = f(i);
		int j = 1, cnt = 0;
		for(; j <= n; j++) {
			if(used[j]) continue;
			if(j == y) break;
			cnt++;
		}
		m += cnt * fact;
		used[y] = true;
	}
	cout << m;
}