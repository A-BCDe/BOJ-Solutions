#pragma GCC optimize("Ofast")
#include <algorithm>
#include <iostream>
#include <queue>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;
struct uf {
	int r, c;
	int *root, *rank;
	uf(int r, int c) : r(r), c(c), root(new int[r * c]), rank(new int[r * c]()) {
		for(int i = 0; i < r * c; i++) root[i] = i;
	}
	int find(int i, int j) { return find(idx(i, j)); }
	void merge(int a1, int a2, int b1, int b2) { merge(idx(a1, a2), idx(b1, b2)); }
	bool check(int a1, int a2, int b1, int b2) { return check(idx(a1, a2), idx(b1, b2)); }
private:
	[[nodiscard]] int idx(int i, int j) const { return i * c + j; }
	int find(int a) {
		if(a == root[a]) return a;
		return root[a] = find(root[a]);
	}
	void merge(int a, int b) {
		int x = find(a);
		int y = find(b);
		if(x == y) return;
		if(rank[x] > rank[y]) swap(x, y);
		root[x] = y;
		if(rank[x] == rank[y]) rank[y]++;
	}
	bool check(int a, int b) { return find(a) == find(b); }
};
struct hash_s {
	size_t operator()(pair<int, int> const &p) const {
		return (((unsigned long long)p.first) << 32) | (unsigned long long)p.second;
	}
};
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int r, c;
	cin >> r >> c;
	auto a = new char*[r];
	auto visited = new bool*[r];
	pair<int, int> L[2]; int lc = 0;
	for(int i = 0; i < r; i++) {
		visited[i] = new bool[c]();
		a[i] = new char[c + 1];
		cin >> a[i];
		for(int j = 0; j < c; j++) {
			if(a[i][j] == 'L') {
				L[lc++] = { i, j };
				a[i][j] = '.';
			}
		}
	}
	vector<pair<int, int>> approach;
	approach.push_back(L[0]);
	uf u(r, c);
	vector<pair<int, int>> erasev;
	for(int i = 0; i < r; i++) {
		for(int j = 0; j < c; j++) {
			if(a[i][j] == '.') {
				queue<pair<int, int>> q;
				q.push({ i, j });
				while(!q.empty()) {
					auto const now = q.front(); q.pop();
					if(visited[now.first][now.second]) continue;
					visited[now.first][now.second] = true;
					if(a[now.first][now.second] == 'X') {
						erasev.push_back(now);
						continue;
					}
					if(now.first && !visited[now.first - 1][now.second]) {
						q.push({ now.first - 1, now.second });
					}
					if(now.first < r - 1 && !visited[now.first + 1][now.second]) {
						q.push({ now.first + 1, now.second });
					}
					if(now.second && !visited[now.first][now.second - 1]) {
						q.push({ now.first, now.second - 1 });
					}
					if(now.second < c - 1 && !visited[now.first][now.second + 1]) {
						q.push({ now.first, now.second + 1 });
					}
				}
			}
		}
	}
	for(int i = 0; i < r; i++) {
		fill(visited[i], visited[i] + c, false);
	}
	for(int t = 0; ; t++) {
		vector<pair<int, int>> nextv;
		queue<pair<int, int>> q;
		for(auto now : approach) q.push(now);
		while(!q.empty()) {
			auto const now = q.front(); q.pop();
			if(visited[now.first][now.second]) continue;
			visited[now.first][now.second] = true;
			if(now.first && !visited[now.first - 1][now.second]) {
				u.merge(now.first, now.second, now.first - 1, now.second);
				if(a[now.first - 1][now.second] == 'X') {
					nextv.emplace_back(now.first - 1, now.second);
				}
				else {
					q.push({ now.first - 1, now.second });
				}
			}
			if(now.first < r - 1 && !visited[now.first + 1][now.second]) {
				u.merge(now.first + 1, now.second, now.first, now.second);
				if(a[now.first + 1][now.second] == 'X') {
					nextv.emplace_back(now.first + 1, now.second);
				}
				else {
					q.push({ now.first + 1, now.second });
				}
			}
			if(now.second && !visited[now.first][now.second - 1]) {
				u.merge(now.first, now.second - 1, now.first, now.second);
				if(a[now.first][now.second - 1] == 'X') {
					nextv.emplace_back(now.first, now.second - 1);
				}
				else {
					q.push({ now.first, now.second - 1 });
				}
			}
			if(now.second < c - 1 && !visited[now.first][now.second + 1]) {
				u.merge(now.first, now.second + 1, now.first, now.second);
				if(a[now.first][now.second + 1] == 'X') {
					nextv.emplace_back(now.first, now.second + 1);
				}
				else {
					q.push({ now.first, now.second + 1 });
				}
			}
		}
		approach.clear();
		approach = move(nextv);
		if(u.check(L[0].first, L[0].second, L[1].first, L[1].second)) {
			cout << t;
			return 0;
		}
		unordered_set<pair<int, int>, hash_s> erasenextv;
		for(auto const &now : erasev) {
			a[now.first][now.second] = '.';
		}
		for(auto const &now : erasev) {
			if(now.first && a[now.first - 1][now.second] == 'X') {
				erasenextv.insert(make_pair(now.first - 1, now.second));
			}
			if(now.first < r - 1 && a[now.first + 1][now.second] == 'X') {
				erasenextv.insert({ now.first + 1, now.second });
			}
			if(now.second && a[now.first][now.second - 1] == 'X') {
				erasenextv.insert({ now.first, now.second - 1 });
			}
			if(now.second < c - 1 && a[now.first][now.second + 1] == 'X') {
				erasenextv.insert({ now.first, now.second + 1 });
			}
		}
		erasev.clear();
		for(auto now : erasenextv) erasev.emplace_back(move(now));
	}
}