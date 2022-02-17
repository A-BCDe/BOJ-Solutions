#include <array>
#include <iostream>
using namespace std;
bool possible(array<array<bool, 5>, 5> const& a, int x, int y, int i) {
	switch (i) {
	case 0: return x && !a[x - 1][y];
	case 1: return y && !a[x][y - 1];
	case 2: return x < 4 && !a[x + 1][y];
	case 3: return y < 4 && !a[x][y + 1];
	default: return false;
	}
}
int move(bool x, int pos, int i) {
	if (x) {
		switch (i) {
		case 0: return pos - 1;
		case 2: return pos + 1;
		default: return pos;
		}
	}
	else {
		switch (i) {
		case 1: return pos - 1;
		case 3: return pos + 1;
		default: return pos;
		}
	}
}
long long f(array<array<bool, 5>, 5>& a, int jx, int jy, int hx, int hy) {
	if (jx == hx && jy == hy) {
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				if (a[i][j] || (!a[i][j] && i == jx && j == jy)) continue;
				return 0;
			}
		}
		return 1;
	}
	a[jx][jy] = a[hx][hy] = true;
	long long res = 0;
	for (int i = 0; i < 4; i++) {
		if (!possible(a, jx, jy, i)) continue;
		for (int j = 0; j < 4; j++) {
			if (!possible(a, hx, hy, j)) continue;
			res += f(a, move(true, jx, i), move(false, jy, i), move(true, hx, j), move(false, hy, j));
		}
	}
	a[jx][jy] = a[hx][hy] = false;
	return res;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n; cin >> n;
	array<array<bool, 5>, 5> a{};
	for (int i = 0; i < n; i++) {
		int x, y; cin >> x >> y;
		a[x - 1][y - 1] = true;
	}
	cout << f(a, 0, 0, 4, 4);
}