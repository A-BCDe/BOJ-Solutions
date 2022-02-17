#include <iostream>
using namespace std;
using ll = unsigned long long;
constexpr ll M = 1000000007;
struct str { ll a, b, x; };
void init(str* t, ll const* a, ll tidx, ll l, ll r) {
	if (l == r) {
		t[tidx].a = 1;
		t[tidx].b = 0;
		t[tidx].x = a[l] % M;
		return;
	}
	auto const m = (l + r) / 2;
	init(t, a, tidx * 2, l, m);
	init(t, a, tidx * 2 + 1, m + 1, r);
	t[tidx].a = 1;
	t[tidx].b = 0;
	t[tidx].x = (t[tidx * 2].x + t[tidx * 2 + 1].x) % M;
}
inline ll calc(str const& s, ll n) { return ((s.x * s.a) % M + (s.b * n) % M) % M; }
void add(str* t, ll tidx, ll start, ll end, ll v, ll l, ll r) {
	if (end < l || r < start) return;
	if (start <= l && r <= end) {
		t[tidx].b = (t[tidx].b + v) % M;
		return;
	}
	auto const m = (l + r) / 2;
	if (t[tidx].a != 1 || t[tidx].b) {
		t[tidx * 2].a = (t[tidx * 2].a * t[tidx].a) % M;
		t[tidx * 2].b = ((t[tidx * 2].b * t[tidx].a) % M + t[tidx].b) % M;
		t[tidx * 2 + 1].a = (t[tidx * 2 + 1].a * t[tidx].a) % M;
		t[tidx * 2 + 1].b = ((t[tidx * 2 + 1].b * t[tidx].a) % M + t[tidx].b) % M;
		t[tidx].a = 1;
		t[tidx].b = 0;
	}
	add(t, tidx * 2, start, end, v, l, m);
	add(t, tidx * 2 + 1, start, end, v, m + 1, r);
	auto const x = calc(t[tidx * 2], m - l + 1);
	auto const y = calc(t[tidx * 2 + 1], r - m);
	t[tidx].x = (x + y) % M;
}
void mul(str* t, ll tidx, ll start, ll end, ll v, ll l, ll r) {
	if (end < l || r < start) return;
	if (start <= l && r <= end) {
		t[tidx].a = (t[tidx].a * v) % M;
		t[tidx].b = (t[tidx].b * v) % M;
		return;
	}
	auto const m = (l + r) / 2;
	if (t[tidx].a != 1 || t[tidx].b) {
		t[tidx * 2].a = (t[tidx * 2].a * t[tidx].a) % M;
		t[tidx * 2].b = ((t[tidx * 2].b * t[tidx].a) % M + t[tidx].b) % M;
		t[tidx * 2 + 1].a = (t[tidx * 2 + 1].a * t[tidx].a) % M;
		t[tidx * 2 + 1].b = ((t[tidx * 2 + 1].b * t[tidx].a) % M + t[tidx].b) % M;
		t[tidx].a = 1;
		t[tidx].b = 0;
	}
	mul(t, tidx * 2, start, end, v, l, m);
	mul(t, tidx * 2 + 1, start, end, v, m + 1, r);
	auto const x = calc(t[tidx * 2], m - l + 1);
	auto const y = calc(t[tidx * 2 + 1], r - m);
	t[tidx].x = (x + y) % M;
}
void val(str* t, ll tidx, ll start, ll end, ll v, ll l, ll r) {
	if (end < l || r < start) return;
	if (start <= l && r <= end) {
		t[tidx].a = 0;
		t[tidx].b = v % M;
		return;
	}
	auto const m = (l + r) / 2;
	if (t[tidx].a != 1 || t[tidx].b) {
		t[tidx * 2].a = (t[tidx * 2].a * t[tidx].a) % M;
		t[tidx * 2].b = ((t[tidx * 2].b * t[tidx].a) % M + t[tidx].b) % M;
		t[tidx * 2 + 1].a = (t[tidx * 2 + 1].a * t[tidx].a) % M;
		t[tidx * 2 + 1].b = ((t[tidx * 2 + 1].b * t[tidx].a) % M + t[tidx].b) % M;
		t[tidx].a = 1;
		t[tidx].b = 0;
	}
	val(t, tidx * 2, start, end, v, l, m);
	val(t, tidx * 2 + 1, start, end, v, m + 1, r);
	auto const x = calc(t[tidx * 2], m - l + 1);
	auto const y = calc(t[tidx * 2 + 1], r - m);
	t[tidx].x = (x + y) % M;
}
ll sum(str* t, ll tidx, ll start, ll end, ll l, ll r) {
	if (end < l || r < start) return 0;
	if (start <= l && r <= end) return calc(t[tidx], r - l + 1);
	auto const m = (l + r) / 2;
	if (t[tidx].a != 1 || t[tidx].b) {
		t[tidx].x = calc(t[tidx], r - l + 1);
		t[tidx * 2].a = (t[tidx * 2].a * t[tidx].a) % M;
		t[tidx * 2].b = ((t[tidx * 2].b * t[tidx].a) % M + t[tidx].b) % M;
		t[tidx * 2 + 1].a = (t[tidx * 2 + 1].a * t[tidx].a) % M;
		t[tidx * 2 + 1].b = ((t[tidx * 2 + 1].b * t[tidx].a) % M + t[tidx].b) % M;
		t[tidx].a = 1, t[tidx].b = 0;
	}
	auto const x = sum(t, tidx * 2, start, end, l, m);
	auto const y = sum(t, tidx * 2 + 1, start, end, m + 1, r);
	return (x + y) % M;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, m;
	cin >> n;
	auto a = new ll[n + 1];
	auto t = new str[n * 4];
	for (int i = 1; i <= n; i++) cin >> a[i];
	init(t, a, 1, 1, n);
	delete[] a;
	cin >> m;
	while (m--) {
		ll w, x, y, z;
		cin >> w >> x >> y;
		switch(w) {
		case 1:
			cin >> z;
			add(t, 1, x, y, z, 1, n);
			break;
		case 2:
			cin >> z;
			mul(t, 1, x, y, z, 1, n);
			break;
		case 3:
			cin >> z;
			val(t, 1, x, y, z, 1, n);
			break;
		case 4:
			cout << sum(t, 1, x, y, 1, n) % M << '\n';
			break;
		}
		if (w == 4) {
			continue;
		}
	}
	delete[] t;
}