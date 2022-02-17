#include <iostream>
#include <queue>
#include <vector>
using namespace std;
class graph {
	struct edge;
	using vertex = vector<edge*>;
	struct edge {
		vertex *u, *v;
		edge* reverse;
		int capacity;
		edge(vertex* u, vertex* v, int capacity) : u(u), v(v), capacity(capacity) {}
	};
	int n, m;
	vertex* vertices;
public:
	graph(int n, int m) : n(n), m(m), vertices(new vertex[n + m + 2]) {
		for (int i = 0; i < n; i++) add_edge(0, i + 2);
		for (int i = 0; i < m; i++) add_edge(i + n + 2, 1);
	}
	void add_edge(int u, int v) {
		auto forward = new edge(vertices + u, vertices + v, 1);
		auto reverse = new edge(vertices + v, vertices + u, 0);
		forward->reverse = reverse;
		reverse->reverse = forward;
		vertices[u].push_back(forward);
		vertices[v].push_back(reverse);
	}
	bool find_path() {
		queue<pair<int, edge*>> q;
		q.push({ 0, nullptr });
		auto dp = new edge*[n + m + 2]();
		auto visited = new bool[n + m + 2]();
		while (!q.empty()) {
			auto const now = q.front(); q.pop();	
			if (visited[now.first]) continue;
			visited[now.first] = true;
			dp[now.first] = now.second;
			if (now.first == 1) {
				int cur = 1;
				while (cur) {
					dp[cur]->capacity--;
					dp[cur]->reverse->capacity++;
					cur = dp[cur]->u - vertices;
				}
				delete[] dp;
				delete[] visited;
				return true;
			}
			for (auto e : vertices[now.first]) {
				int const next = e->v - vertices;
				if (visited[next] || !e->capacity) continue;
				q.push({ next, e });
			}
		}
		delete[] dp;
		delete[] visited;
		return false;
	}
};
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, m;
	cin >> n >> m;
	graph g(n, m);
	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		for (int j = 0; j < k; j++) {
			int x;
			cin >> x;
			g.add_edge(i + 2, x + n + 1);
		}
	}
	int res = 0;
	while (g.find_path()) res++;
	cout << res;
}