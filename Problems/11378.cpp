#include <algorithm>
#include <iostream>
#include <memory>
#include <queue>
#include <vector>
#include <utility>
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
		static pair<edge*, edge*> add_edge(vertex* u, vertex* v, int capacity) {
			auto forward = new edge(u, v, capacity);
			auto reverse = new edge(v, u, 0);
			forward->reverse = reverse;
			reverse->reverse = forward;
			return { forward, reverse };
		}

		void fill(int c) {
			capacity -= c;
			reverse->capacity += c;
		}
		int size() const { return capacity; }
		bool full() const { return !capacity; }
		vertex* next() const { return v; }
	};
	class vertex {
		vector<edge*> edges;

	public:
		friend class graph;
		void add_edge(vertex *v, int capacity) {
			auto p = edge::add_edge(this, v, capacity);
			edges.push_back(p.first);
			v->edges.push_back(p.second);
		}
	};

	int find_path(int start, int end) {
		queue<pair<int, pair<int, vector<edge*>>>> q;
		q.push(make_pair(start, make_pair(n + k + 1, vector<edge*>())));
		auto visited = make_unique<bool[]>(n + m + 3);
		while (!q.empty()) {
			auto now = q.front(); q.pop();
			if (visited[now.first]) continue;
			visited[now.first] = true;
			if (now.first == end) {
				auto& v = now.second.second;
				for (auto e : v) {
					e->fill(now.second.first);
				}
				return now.second.first;
			}
			for (auto e : vertices[now.first].edges) {
				auto next = e->next();
				if (e->full() || visited[next - vertices]) continue;
				auto v = now.second.second;
				v.push_back(e);
				q.push(make_pair(next - vertices, make_pair(min(now.second.first, e->size()), v)));
			}
		}
		return 0;
	}

	int n, m, k;
	vertex* vertices;
public:
	graph(int n, int m, int k) : n(n), m(m), k(k), vertices(new vertex[n + m + 3]) {
		// start : vertices[0]
		// mid   : vertices[1]
		// end   : vertices[2]
		// worker: vertices[3 ~ n + 2]
		// work  : vertices[n + 3 ~ n + m + 2]
		vertices[0].add_edge(vertices + 1, n + k);
		for (int i = 0; i < n; i++) {
			auto const now = 3 + i;
			vertices[1].add_edge(vertices + now, k + 1);
		}
		for (int i = 0; i < m; i++) {
			auto const now = n + 3 + i;
			vertices[now].add_edge(vertices + 2, 1);
		}
	}

	void add_edge(int u, int v, int capacity) {
		vertices[u].add_edge(vertices + v, capacity);
	}

	int find_path() { return find_path(0, 2); }
};
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, m, k;
	cin >> n >> m >> k;
	graph g(n, m, k);
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x;
		for (int i = 0; i < x; i++) {
			cin >> y;
			g.add_edge(i + 3, y + n + 2, 1);
		}
	}
	int res = 0;
	int path;
	while (path = g.find_path()) res += path;
	cout << res;
}