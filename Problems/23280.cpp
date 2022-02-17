#include <algorithm>
#include <stdio.h>
#include <cstring>
#include <numeric>
#include <utility>
using std::pair;
inline pair<int, int> num_to_coord(int n) { return { (n + 1) / 3, (n + 1) % 3 }; }
inline int inv(pair<int, int> const& p) { return p.first * 3 + p.second - 1; }
inline int dist(pair<int, int> const& a, pair<int, int> const& b) {
	return abs(a.first - b.first) + abs(a.second - b.second);
}
struct info {
	pair<int, int> left, right;
	int hp;
};
int main() {
	int n, a, b;
	scanf("%d%d%d", &n, &a, &b);

}