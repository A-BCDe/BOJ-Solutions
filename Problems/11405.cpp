#include <algorithm>
#include <iostream>
#include <memory>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
class graph {
	class vertex;
	class edge {
		int capacity, length;
		edge* reverse;
		edge(vertex* u, vertex* v, int capacity, int length) : u(u), v(v), capacity(capacity), length(length), reverse(nullptr) {}
	public:
		vertex* u;
		vertex* v;
		static pair<edge*, edge*> make_edge(vertex* u, vertex* v, int capacity, int length) {
			auto forward = new edge(u, v, capacity, length);
			auto reverse = new edge(v, u, 0, -length);
			forward->reverse = reverse;
			reverse->reverse = forward;
			return { forward, reverse };
		}
		void fill(int f) {
			capacity -= f;
			reverse->capacity += f;
		}
		bool full() const { return !capacity; }
		int len() const { return length; }
		int size() const { return capacity; }
	};
	class vertex {
	public:
		vector<edge*> edges;
		void add_edge(vertex* v, int capacity, int length) {
			auto const p = edge::make_edge(this, v, capacity, length);
			edges.push_back(p.first);
			v->edges.push_back(p.second);
		}
	};
	using type = pair<pair<int, int>, pair<int, edge*>>;
	struct comp {
		bool operator()(type const& a, type const& b) {
			return a.first.first > b.first.first;
		}
	};
	int n, m, total_length;
	vertex* vertices;
public:
	// 0 : start
	// 1 : end
	// 2 ~ m + 1 : book
	// m + 2 ~ n + m + 1 : people
	graph(int n, int m) : n(n), m(m), total_length(0), vertices(new vertex[n + m + 2]) {}
	int people(int x) const { return m + x + 2; }
	int book(int x) const { return x + 2; }
	void add_edge(int u, int v, int capacity, int length) {
		vertices[u].add_edge(vertices + v, capacity, length);
	}
	int find_path() {
		int const start = 0, end = 1;
		int const M = 1000000001;
		queue<type> q;
		q.push({ { 0, start }, { 1000001, nullptr } });
		auto dist = make_unique<int[]>(n + m + 2);
		auto prev = make_unique<edge*[]>(n + m + 2); // vertex index -> previous vertex
		int flow = 0;
		fill(dist.get(), dist.get() + n + m + 2, M);
		while (!q.empty()) {
			auto const now = q.front(); q.pop();
			if (dist[now.first.second] <= now.first.first) continue;
			dist[now.first.second] = now.first.first;
			prev[now.first.second] = now.second.second;
			if (now.first.second == end) {
				flow = now.second.first;
				continue;
			}
			for (auto e : vertices[now.first.second].edges) {
				auto const next = e->v - vertices;
				if (e->full()) continue;
				q.push({ { now.first.first + e->len(), next }, { min(now.second.first, e->size()), e } });
			}
		}
		int idx = 1;
		while (prev[idx]) {
			prev[idx]->fill(flow);
			idx = prev[idx]->u - vertices;
		}
		return flow;
	}
	int result() const { return total_length; }
};
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, m;
	cin >> n >> m;
	graph g(n, m);
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		g.add_edge(g.people(i), 1, x, 0);
	}
	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		g.add_edge(0, g.book(i), x, 0);
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			int x;
			cin >> x;
			g.add_edge(g.book(i), g.people(j), 100001, x);
		}
	}
	while (g.find_path());
	cout << g.result();
}