#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
struct Monkey {
	int left, right, fall;
	bool const &lefthand;
	bool const &righthand;
	Monkey(int left, int right, int fall, bool const &lefthand, bool const &righthand)
	  : left(left), right(right), fall(fall), lefthand(lefthand), righthand(righthand) {}
};
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, m;
	cin >> n >> m;
	vector<Monkey> v;
	vector<vector<bool>> arr;
	arr.reserve(n + 1);
	arr.emplace_back();
	for(int i = 1; i <= n; i++) {
		arr.emplace_back(n + 1);
	}
	v.reserve(n);
	for(int i = 1; i <= n; i++) {
		int l, r;
		cin >> l >> r;
		v.emplace_back(l, r, -1, arr[min(l, i)][max(l, i)], arr[min(r, i)][max(r, i)]);
		
	}
}