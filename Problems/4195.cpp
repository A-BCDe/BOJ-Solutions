#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <utility>
using namespace std;
using ull = unsigned long long;
struct uf {
	ull const n;
	unordered_map<string, ull> m;
	pair<ull, ull>* const root;
	ull* const rank;
	uf(unordered_set<string> const& s) : n(s.size()), root(new pair<ull, ull>[s.size()]), rank(new ull[s.size()]()) {
		ull idx = 0;
		for (auto const& str : s) {
			m[str] = idx;
			root[idx] = { idx, 1 };
			idx++;
		}
	}
	~uf() {
		delete[] root;
		delete[] rank;
	}
	ull find(ull a) {
		if (root[a].first == a) return a;
		return root[a].first = find(root[a].first);
	}
	ull find(string const& s) {
		return find(m[s]);
	}
	ull merge(ull a, ull b) {
		auto x = find(a);
		auto y = find(b);
		if (x == y) return root[y].second;
		if (rank[x] > rank[y]) swap(x, y);
		root[x].first = y;
		root[y].second += root[x].second;
		rank[y] += (rank[x] == rank[y]);
		return root[y].second;
	}
	ull merge(string const& s, string const& t) { return merge(m[s], m[t]); }
};
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		unordered_set<string> s;
		auto p = new pair<string, string>[n];
		for (int i = 0; i < n; i++) {
			cin >> p[i].first >> p[i].second;
			s.insert(p[i].first);
			s.insert(p[i].second);
		}
		uf f(s);
		for (int i = 0; i < n; i++) {
			cout << f.merge(p[i].first, p[i].second) << '\n';
		}
		delete[] p;
	}
}