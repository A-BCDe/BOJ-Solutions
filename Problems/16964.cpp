#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
bool dfs(vector<int> const *v, vector<int> const &input, bool *visited, int now, int prev, int &idx) {
	if(visited[now]) return false;
	visited[now] = true;
	for(int i = 0; i < v[now].size() - (now != 1); i++) {
		idx++;
		auto p = lower_bound(v[now].begin(), v[now].end(), input[idx]);
		if(p == v[now].end() || *p != input[idx] || *p == prev) return false;
		if(visited[*p]) return false;
		if(!dfs(v, input, visited, input[idx], now, idx)) return false;
	}
	return true;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin >> n;
	auto v = new vector<int>[n + 1];
	for(int i = 1; i < n; i++) {
		int x, y; cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for(int i = 1; i <= n; i++) {
		sort(v[i].begin(), v[i].end());
	}
	vector<int> input;
	for(int i = 0; i < n; i++) {
		int x;
		cin >> x;
		input.push_back(x);
	}
	auto visited = new bool[n + 1]();
	int idx = 0;
	cout << dfs(v, input, visited, 1, 0, idx);
	delete[] v;
}