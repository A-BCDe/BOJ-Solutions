#pragma GCC optimize("Ofast")
#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;
class graph {
	class edge;
	class vertex {
	public:
		vector<edge*> edges;
		void add_edge(vertex *const v) {
			auto const p = edge::make_edge(this, v);
			edges.push_back(p.first);
			v->edges.push_back(p.second);
		}
	};
	class edge {
		vertex *const v;
		edge *reverse;
		bool match;
		explicit edge(vertex *v) : v(v), reverse(nullptr), match(false) {}
	public:
		static pair<edge*, edge*> make_edge(vertex *const u, vertex *const v) {
			auto const forward = new edge(v);
			auto const backward = new edge(u);
			forward->reverse = backward;
			backward->reverse = forward;
			return make_pair(forward, backward);
		}
		[[nodiscard]] vertex *next() const { return v; }
		[[nodiscard]] bool matched() const { return match; }
		void flip() { match = reverse->match = !match; }
	};
	int const n, m;
	vertex *const vertices;
public:
	graph(int n, int m) : n(n), m(m), vertices(new vertex[n + m]) {}
	void add_edge(int u, int v) const { vertices[u].add_edge(vertices + n + v); }
	[[nodiscard]] int find() const {
		auto const visited = new bool[n + m]();
		int cnt = 0;
		for(int i = 0; i < n; i++) {
			for(auto e : vertices[i].edges) {
				if(!dfs(e, visited)) continue;
				cnt++;
				break;
			}
		}
		delete[] visited;
		return cnt;
	}
	[[nodiscard]] bool dfs(edge *const e, bool *const visited) const {
		auto const v = e->next();
		visited[v - vertices] = true;
		if(e->matched()) {
			for(auto const nexte : v->edges) {
				if(visited[nexte->next() - vertices]) continue;
				if(dfs(nexte, visited)) {
					e->flip();
					visited[v - vertices] = false;
					return true;
				}
			}
			visited[v - vertices] = false;
			return false;
		}
		for(auto const nexte : v->edges) {
			if(nexte->matched()) {
				if(!visited[nexte->next() - vertices] && dfs(nexte, visited)) {
					e->flip();
					visited[v - vertices] = false;
					return true;
				}
				visited[v - vertices] = false;
				return false;
			}
		}
		e->flip();
		visited[v - vertices] = false;
		return true;
	}
};
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, m;
	cin >> n >> m;
	graph g(n, m);
	while(n--) {
		int k, x;
		cin >> k;
		while(k--) {
			cin >> x;
			g.add_edge(n, x - 1);
		}
	}
	cout << g.find();
}