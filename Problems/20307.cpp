#include <iostream>
#include <cassert>
#include <string>
using namespace std;
using ll = long long;
struct rat {
	long long n, d;
	rat() : n(0), d(1) {}
	rat(long long n, long long d) : n(n), d(d) { assert(d != 0); }
	rat operator+(rat a) const {
		ll new_d = lcm(a.d, d);
		ll new_r = (new_d / a.d) * a.n + (new_d / d) * n;
		ll g = gcd(new_r, new_d);
		return rat(new_r / g, new_d / g);
	}
	rat operator-(rat a) const {
		ll new_d = lcm(a.d, d);
		ll new_r = (new_d / d) * n - (new_d / a.d) * a.n;
		ll g = gcd(new_r, new_d);
		return rat(new_r / g, new_d / g);
	}
	rat operator*(rat a) const {
		ll new_d = a.d * d;
		ll new_r = a.n * n;
		ll g = gcd(new_r, new_d);
		return rat(new_r / g, new_d / g);
	}
	rat operator/(rat a) const {
		ll new_d = d * a.n;
		ll new_r = n * a.d;
		ll g = gcd(new_r, new_d);
		if (new_d < 0) {
			new_r = -new_r;
			new_d = -new_d;
		}
		return rat(new_r / g, new_d / g);
	}
	bool is_zero() const { return n == 0; }
	friend ostream &operator<<(ostream& os, rat& r) {
		auto g = gcd(r.n, r.d);
		r.n /= g;
		r.d /= g;
		if (r.d == 1 || r.n == 0) {
			os << r.n;
		}
		else {
			os << r.n << '/' << r.d;
		}
		return os;
	}
	static long long abs(long long a) { return a > 0 ? a : -a; }
	static long long gcd(long long a, long long b) {
		if (b == 0) return abs(a);
		return gcd(abs(b), abs(a) % b);
	}
	static long long lcm(long long a, long long b) {
		return a / gcd(a, b) * b;
	}
};
void read_rat(string const &s, int& idx, rat& r) {
	bool sign = false;
	while (s[idx] <= ' ') idx++;
	if (s[idx] == '-') { sign = true; idx++; }
	int n = 0;
	while (s[idx] >= '0' && s[idx] <= '9') {
		n *= 10;
		n += s[idx++] - '0';
	}
	if (s[idx] != '/') {
		r.n = n;
		if (sign) r.n = -r.n;
		r.d = 1;
		return;
	}
	int d = 0;
	idx++;
	while (s[idx] >= '0' && s[idx] <= '9') {
		d *= 10;
		d += s[idx++] - '0';
	}
	r.n = n;
	if (sign) r.n = -r.n;
	r.d = d;
}
int main() {
	int n, m;
	cin >> n >> m;
	auto a = new rat* [n];
	for (int i = 0; i < n; i++) {
		a[i] = new rat[m];
		string s;
		do {
			getline(cin, s);
		} while (s == "");
		int idx = 0;
		for (int j = 0; j < m; j++) {
			read_rat(s, idx, a[i][j]);
		}
	}
	int rank = 0;
	for (int i = 0; i < m && rank < n && rank < m; i++) {
		int nonzero = -1;
		for (int j = rank; j < n; j++) {
			if (a[j][i].n != 0) {
				nonzero = j;
				break;
			}
		}
		if (nonzero == -1) continue;
		if (nonzero != rank) {
			for (int j = 0; j < m; j++) {
				auto tmp = a[rank][j];
				a[rank][j] = a[nonzero][j];
				a[nonzero][j] = tmp;
			}
		}
		auto const d = a[rank][i];
		for (int j = 0; j < m; j++) {
			a[rank][j] = a[rank][j] / d;
		}
		for (int j = 0; j < n; j++) {
			if (j == rank) continue;
			auto div = a[j][i] / a[rank][i];
			for (int k = 0; k < m; k++) {
				a[j][k] = a[j][k] - div * a[rank][k];
			}
		}
		rank++;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << a[i][j] << ' ';
		}
		cout << '\n';
	}
}