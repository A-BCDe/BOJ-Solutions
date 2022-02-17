#include <stdio.h>
#include <memory>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
class graph {
	class vertex;
	class edge {
		using vertex_pointer = vertex*;
	public:
		static pair<edge*, edge*> make_edge(vertex_pointer u, vertex_pointer v, int capacity) {
			auto forward = new edge(u, v, capacity);
			auto reverse = new edge(v, u, 0);
			forward->reverse = reverse;
			reverse->reverse = forward;
			return { forward, reverse };
		}

		void fill(int size) {
			capacity -= size;
			reverse->capacity += size;
		}

		vertex_pointer next() const { return v; }
		bool full() const { return capacity == 0; }
	private:
		vertex_pointer u, v;
		int capacity;
		edge* reverse;

		edge(vertex_pointer u, vertex_pointer v, int capacity)
			: u(u), v(v), capacity(capacity), reverse(nullptr) {}
	};
	class vertex {
	public:
		vertex() = default;

		void add_edge(vertex* v, int capacity) {
			auto p = edge::make_edge(this, v, capacity);
			edges.push_back(p.first);
			v->edges.push_back(p.second);
		}
		
		friend class graph;
	private:
		vector<edge*> edges;
	};
public:
	explicit graph(int n) : n(n), vertices(new vertex[n + 1]) {}

	void add_edge(int u, int v, int capacity) {
		vertices[u].add_edge(vertices + v, capacity);
	}

	bool find_path() { return find_path(1, 2); }

private:
	int n;
	vertex* vertices;

	bool find_path(int start, int end) {
		queue<pair<int, queue<edge*>>> q;
		q.push(make_pair(1, queue<edge*>()));
		auto visited = new bool[n + 1]();
		while (!q.empty()) {
			auto now = q.front(); q.pop();
			if (visited[now.first]) continue;
			visited[now.first] = true;
			if (now.first == end) {
				int const fill = 1;
				auto& qu = now.second;
				while (!qu.empty()) {
					qu.front()->fill(fill);
					qu.pop();
				}
				delete[] visited;
				return true;
			}
			for (auto next : vertices[now.first].edges) {
				int const next_node = next->next() - vertices;
				if (!visited[next_node] && !next->full()) {
					auto qu = now.second;
					qu.push(next);
					q.push(make_pair(next_node, move(qu)));
				}
			}
		}
		delete[] visited;
		return false;
	}
};
int main() {
	int n, p;
	scanf("%d%d", &n, &p);
	graph g(n);
	for (int i = 0; i < p; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		g.add_edge(x, y, 1);
	}
	int res = 0;
	while (g.find_path()) res++;
	printf("%d", res);
}