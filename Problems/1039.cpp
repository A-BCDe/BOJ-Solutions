#include <algorithm>
#include <cassert>
#include <iostream>
#include <set>
#include <string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	string n; int k;
	cin >> n >> k;
	for (int i = 0; i < 10; i++) {
		if (to_string(i) == n || to_string(i * 10) == n) {
			cout << -1;
			return 0;
		}
	}
	
}