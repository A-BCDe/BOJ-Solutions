#include <iostream>
#include <deque>
#include <queue>
#include <set>
using namespace std;
struct str { int n, next; };
struct comp { bool operator()(str const& a, str const& b) { return a.next < b.next; } };
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, k;
	cin >> n >> k;
	auto a = new int[k];
	auto d = new deque<int>[k + 1];
	for (int i = 0; i < k; i++) {
		int x; cin >> x;
		a[i] = x;
		d[x].push_back(i);
	}
	priority_queue<str, vector<str>, comp> pq;
	set<int> s;
	int cnt = 0;
	for (int i = 0; i < k; i++) {
		if (pq.size() == n) {
			if (s.find(a[i]) != s.end()) {
				n++;
			}
			else {
				s.erase(pq.top().n);
				pq.pop();
				cnt++;
			}
		}
		else if (s.find(a[i]) != s.end()) n++;
		if (d[a[i]].size() < 2) pq.push({ a[i], k + 1 });
		else pq.push({ a[i], d[a[i]][1] });
		s.insert(a[i]);
		d[a[i]].pop_front();
	}
	cout << cnt;
}