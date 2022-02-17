#include <algorithm>
#include <set>
#include <stdio.h>
#include <utility>
using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	set<pair<int, pair<int, int>>> a;
	for (int i = 0; i < n; i++) {
		int x, y, cnt = 0;
		scanf("%d%d", &x, &y);
		for (auto it = a.begin(); it != a.end(); it++) {
			auto& now = *it;
			if ((x < now.second.first && y > now.second.second) || (x > now.second.first && y < now.second.second)) {
				cnt++;
			}
		}
		a.insert(make_pair(0, make_pair(x, y)));
	}
}