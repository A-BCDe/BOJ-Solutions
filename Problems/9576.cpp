#include <algorithm>
#include <stdio.h>
#include <utility>
using namespace std;
int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		int n, m;
		scanf("%d%d", &n, &m);
		auto a = new pair<int, int>[m];
		for(int i = 0; i < m; i++) {
			scanf("%d%d", &a[i].first, &a[i].second);
		}
		sort(a, a + m, [](pair<int, int> const &a, pair<int, int> const &b) {
			return a.second < b.second || (a.second == b.second && a.first < b.first);
		});
		auto visited = new bool[n + 1]();
		int cnt = 0;
		for(int i = 0; i < m; i++) {
			for(int j = a[i].first; j <= a[i].second; j++) {
				if(!visited[j]) {
					visited[j] = true;
					cnt++;
					break;
				}
			}
		}
		printf("%d\n", cnt);
		delete[] visited;
		delete[] a;
	}
}