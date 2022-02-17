#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct str {
	int a, b, c;
	bool operator()(str const& a, str const& b) { return a.a < b.a; }
};
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, m, score = 0;
	cin >> n >> m; n *= 24;
	auto a = new int[m];
	auto b = new int[m];
	auto s = new str[m];
	for (int i = 0; i < m; i++) { cin >> a[i]; score += a[i]; }
	for (int i = 0; i < m; i++) cin >> b[i];
	for (int i = 0; i < m; i++) {
		if (100 - a[i] < b[i]) s[i] = { 100 - a[i], 1, 0 };
		else s[i] = { b[i], (100 - a[i]) / b[i], (100 - a[i]) % b[i] };
	}
	priority_queue<str, vector<str>, str> pq;
	for (int i = 0; i < m; i++) pq.push(move(s[i]));
	int time = 0;
	while (!pq.empty() && time < n) {
		auto const now = pq.top(); pq.pop();
		int t = n - time;
		if (t > now.b) t = now.b;
		score += now.a * t;
		time += t;
		if (now.c) pq.push({ now.c, 1, 0 });
	}
	cout << score;
}