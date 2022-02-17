#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
void init(vector<pair<int, int>> const* tmpv, int* weight, int* subtree, int now, int prev) {
	subtree[now] = 1;
	for (auto next : tmpv[now]) {
		if (next.first == prev) {
			weight[now] = next.second;
			continue;
		}
		init(tmpv, weight, subtree, next.first, now);
		subtree[now] += subtree[next.first];
	}
}
struct segtree {
	int n;
	int* t;
	segtree(int n) : n(n), t(new int[n * 4]) {}
	void init(int* a) { init(a, 1, 1, n); }
private:
	void init(int* a, int tidx, int l, int r) {
		if (l == r) {
			t[tidx] = a[l];
			return;
		}
		auto const m = (l + r) / 2;
		init(a, tidx * 2, l, m);
		init(a, tidx * 2 + 1, m + 1, r);
		t[tidx] = max(t[tidx * 2], t[tidx * 2 + 1]);
	}
};
struct chain {
	int parent_idx;
	chain* parent;
	segtree* seg;
	vector<int> node_list;
	chain(int parent_idx, chain* parent) : parent_idx(parent_idx), parent(parent), seg(nullptr), node_list() {}
	void add_node(int node) { node_list.push_back(node); }
};
void make_chains(vector<pair<int, int>> const* v, int const* weight, int const* subtree, vector<chain*>& chains, int now, int prev, int idx) {
	chains[idx]->add_node(now);
	int cnt = -1;
	for (auto next : v[now]) {
		if (next.first == prev) continue;
		if (cnt == -1 || subtree[cnt] < subtree[next.first]) {
			cnt = next.first;
		}
	}
	if (cnt == -1) return;
	int cidx = chains[idx]->node_list.size() - 1;
	make_chains(v, weight, subtree, chains, cnt, now, idx);
	for (auto next : v[now]) {
		if (next.first == prev || next.first == cnt) continue;
		chains.emplace_back(new chain(cidx, chains[idx]));
		make_chains(v, weight, subtree, chains, next.first, now, chains.size() - 1);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n; cin >> n;
	auto v = new vector<pair<int, int>>[n + 1];
	for (int i = 1; i < n; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		v[x].emplace_back(y, z);
		v[y].emplace_back(x, z);
	}
	auto weight = new int[n + 1];
	auto subtree = new int[n + 1];
	weight[1] = 0;
	init(v, weight, subtree, 1, -1);
	vector<chain*> chains;
	chains.emplace_back(new chain(-1, nullptr));
	make_chains(v, weight, subtree, chains, 1, -1, 0);

	cout << '\n';
	for (int i = 0; i < chains.size(); i++) {
		cout << "i = " << i << '\n';
		for (auto now : chains[i]->node_list) {
			cout << now << ' ';
		} cout << '\n';
	} cout << '\n';



	delete[] v;
	delete[] weight;
}