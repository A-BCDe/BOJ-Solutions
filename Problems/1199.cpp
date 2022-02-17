#include <stdio.h>
#include <map>
#include <vector>
using namespace std;
/*
5
0 1 1 1 1
1 0 1 1 1
1 1 0 1 1
1 1 1 0 1
1 1 1 1 0
*/
void print(vector<vector<int>> const& cycles, unsigned long long* a, int n, int idx) {
	auto const& cycle = cycles[idx];
	a[cycle[0]]++;
	for (int i = 0; i < cycle.size(); i++) {
		int const cur = cycle[i];
		if (a[cur] < cycles.size() && cycles[a[cur]][0] == cur) {
			print(cycles, a, n, a[cur]);
		}
		printf("%d ", cycle[i] + 1);
	}
}
int main() {
	int n;
	scanf("%d", &n);
	auto m = new map<int, int>[n];
	for (int i = 0; i < n; i++) {
		int sum = 0;
		for (int j = 0; j < n; j++) {
			int x;
			scanf("%d", &x);
			sum += x;
			if (i >= j || !x) continue;
			m[i][j] += x;
			m[j][i] += x;
		}
		if (sum & 1) {
			printf("-1");
			return 0;
		}
	}
	vector<vector<int>> cycles;
	auto a = new unsigned long long[n]();
	for (int i = 0; i < n - 1; i++) {
		a[i] = cycles.size();
		for (int j = i + 1; j < n; j++) {
			while (m[i][j]) {
				m[i][j]--;
				m[j][i]--;
				int cur = j;
				vector<int> v = { i, j };
				while (cur != i) {
					for (auto it = m[cur].begin(); it != m[cur].end();) {
						if (it->second == 0) {
							it = m[cur].erase(it);
							continue;
						}
						m[cur][it->first]--;
						m[it->first][cur]--;
						cur = it->first;
						v.push_back(cur);
						break;
					}
				}
				v.pop_back();
				cycles.emplace_back(move(v));
			}
		}
	}
	a[n - 1] = cycles.size();
	/*printf("a: ");
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	} printf("\n");
	printf("cycles:\n");
	for (auto const& cycle : cycles) {
		for (auto now : cycle) {
			printf("%d ", now);
		}
		printf("\n");
	} printf("\n");*/
	print(cycles, a, n, 0);
	printf("1");
}