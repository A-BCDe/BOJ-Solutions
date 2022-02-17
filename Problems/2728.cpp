#include <algorithm>
#include <iostream>
#include <map>
#include <set>
using namespace std;
using ll = long long;
ll dp(ll** table, int no, int money) {

}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t; cin >> t;
	while (t--) {
		int v, d;
		cin >> v >> d;
		auto table = new ll*[v];
		for (int i = 0; i < v; i++) {
			table[i] = new ll[d + 1]();
			fill(table[i], table[i] + d + 1, -1);
		}
		for (int i = 0; i < v; i++) {
			ll x; cin >> x;
			
		}
		for (int i = 0; i < v; i++) delete[] table[i];
		delete[] table;
	}
}