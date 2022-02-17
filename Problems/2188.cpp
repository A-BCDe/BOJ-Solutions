#include <stdio.h>
#include <memory>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
class graph {
	class vertex;
	class edge {
		vertex* u;
		vertex* v;
		int capacity;
		edge* reverse;
		edge(vertex* u, vertex* v, int capacity) : u(u), v(v), capacity(capacity), reverse(nullptr) {}
	public:
		static pair<edge*, edge*> make_edge(vertex* u, vertex* v, int capacity) {
			auto forward = new edge(u, v, capacity);
			auto reverse = new edge(v, u, 0);
			forward->reverse = reverse;
			reverse->reverse = forward;
			return { forward, reverse };
		}
		void fill(int f) {
			capacity -= f;
			reverse->capacity += f;
		}
		[[nodiscard]] vertex* next() const { return v; }
		[[nodiscard]] bool full() const { return !capacity; }
		[[nodiscard]] int size() const { return capacity; }
	};
	class vertex {
	public:
		vector<edge*> edges;
		void add_edge(vertex* v, int capacity) {
			auto const p = edge::make_edge(this, v, capacity);
			edges.push_back(p.first);
			v->edges.push_back(p.second);
		}
	};
	vertex* vertices;
	int n, m;
public:
	graph(int n, int m) : n(n), m(m), vertices(new vertex[n + m + 2]) {
		for (int i = 0; i < n; i++) {
			add_edge(0, cow(i));
		}
		for (int i = 0; i < m; i++) {
			add_edge(com(i), 1);
		}
	}
	int cow(int x) const { return x + 2; }
	int com(int x) const { return x + n + 2; }
	void add_edge(int u, int v) { vertices[u].add_edge(vertices + v, 1); }
	int find_path() {
		// start = 0, end = 1
		queue<pair<int, pair<int, vector<edge*>>>> q; // current vertex, current flow, passed edges
		q.push({ 0, { 1, {} } });
		auto visited = make_unique<bool[]>(n + m + 2);
		while (!q.empty()) {
			auto now = q.front(); q.pop();
			if (visited[now.first]) continue;
			visited[now.first] = true;
			if (now.first == 1) {
				auto const flow = now.second.first;
				for (auto e : now.second.second) {
					e->fill(flow);
				}
				return flow;
			}
			for (auto e : vertices[now.first].edges) {
				int const next = e->next() - vertices;
				if (visited[next] || e->full()) continue;
				auto v = now.second.second;
				v.push_back(e);
				q.push({ next, { min(now.second.first, e->size()), v } });
			}
		}
		return 0;
	}
};
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	graph g(n, m);
	for (int i = 0; i < n; i++) {
		int k;
		scanf("%d", &k);
		for (int j = 0; j < k; j++) {
			int x;
			scanf("%d", &x);
			g.add_edge(g.cow(i), g.com(x - 1));
		}
	}
	int res = 0, flow;
	while (flow = g.find_path()) {
		res += flow;
	}
	printf("%d", res);
}