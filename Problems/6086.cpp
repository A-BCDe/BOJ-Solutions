#include <algorithm>
#include <stdio.h>
#include <memory>
#include <queue>
#include <vector>
#include <utility>
using namespace std;
inline int index(char c) {
	if (c >= 'a' && c <= 'z') return c - 'a' + 26;
	return c - 'A';
}

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
			auto reverse = new edge(v, u, capacity);
			forward->reverse = reverse;
			reverse->reverse = forward;
			return { forward, reverse };
		}

		bool full() const { return !capacity; }

		void fill(int c) {
			capacity -= c;
			reverse->capacity += c;
		}

		vertex* next() const { return v; }

		int size() const { return capacity; }
	};
	class vertex {
		vector<edge*> edges;
		
	public:
		friend class graph;
		void add_edge(vertex* v, int capacity) { // u = this, v = v, cap = cap
			auto p = edge::make_edge(this, v, capacity);
			edges.push_back(p.first);
			v->edges.push_back(p.second);
		}
	};

	int n;
	vertex* vertices;

	int find_path(int start, int end) {
		queue<pair<int, pair<int, vector<edge*>>>> q; // current vertex, current flow, passed edges
		q.push(make_pair(start, make_pair(1001, vector<edge*>())));
		auto visited = make_unique<bool[]>(n + 1);
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

public:
	graph(int n) : n(n), vertices(new vertex[n + 1]) {}

	void add_edge(char u, char v, int capacity) {
		vertices[index(u)].add_edge(vertices + index(v), capacity);
	}

	int find_path() { return find_path(0, 25); }
};

int main() {
	int k;
	scanf("%d", &k);
	graph g(52);
	for (int i = 0; i < k; i++) {
		char x[2], y[2];
		int z;
		scanf("%s%s%d", x, y, &z);
		g.add_edge(*x, *y, z);
	}
	int flow = 0;
	int res = 0;
	while (flow = g.find_path()) res += flow;
	printf("%d", res);
}