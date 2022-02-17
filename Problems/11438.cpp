#include <iostream>
#include <vector>
using namespace std;
void set_weight(vector<int> const* v, int* weight, int now, int prev) {
	weight[now] = 1;
	for (auto next : v[now]) {
		if (next == prev) continue;
		set_weight(v, weight, next, now);
		weight[now] += weight[next];
	}
}
struct chain {
	int level, adj;
	chain* parent;
	vector<int> node_list;
	chain(int level, int adj, chain* parent = nullptr) : level(level), adj(adj), parent(parent), node_list() {}
	void add_node(int node) { node_list.push_back(node); }
};
struct node_info {
	chain* ch;
	int idx;
};
void hld(vector<int> const* v, int const* weight, vector<chain*>& chains, node_info *info, int now, int prev, int idx) {
	info[now] = { chains[idx], (int)chains[idx]->node_list.size() };
	chains[idx]->add_node(now);
	int cur = prev;
	for (auto next : v[now]) {
		if (next == prev) continue;
		if (cur == prev || weight[cur] < weight[next]) cur = next;
	}
	if (cur == prev) return;
	int const adj = chains[idx]->node_list.size() - 1;
	hld(v, weight, chains, info, cur, now, idx);
	for (auto next : v[now]) {
		if (next == prev || next == cur) continue;
		chains.emplace_back(new chain(chains[idx]->level + 1, adj, chains[idx]));
		hld(v, weight, chains, info, next, now, (int)(chains.size() - 1));
	}
}
int lca(vector<chain*> const& chains, node_info const *info, int x, int y) {
	auto const ix = info[x], iy = info[y];
	if (ix.ch->level == iy.ch->level) {
		if (ix.ch == iy.ch) return ix.idx < iy.idx ? ix.ch->node_list[ix.idx] : iy.ch->node_list[iy.idx];
		return lca(chains, info, ix.ch->parent->node_list[ix.ch->adj], iy.ch->parent->node_list[iy.ch->adj]);
	}
	else if (ix.ch->level < iy.ch->level) return lca(chains, info, x, iy.ch->parent->node_list[iy.ch->adj]);
	else return lca(chains, info, ix.ch->parent->node_list[ix.ch->adj], y);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n; cin >> n;
	auto v = new vector<int>[n + 1];
	auto weight = new int[n + 1];
	for (int i = 1; i < n; i++) {
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	vector<chain*> chains;
	auto info = new node_info[n + 1];
	chains.emplace_back(new chain(1, -1));
	set_weight(v, weight, 1, -1);
	hld(v, weight, chains, info, 1, -1, 0);
	int m, x, y;
	cin >> m;
	while (m--) {
		cin >> x >> y;
		printf("%d\n", lca(chains, info, x, y));
	}
	delete[] weight;
	delete[] v;
}