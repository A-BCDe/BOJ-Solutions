#include <iostream>
#include <deque>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, l;
	cin >> n >> l;
	auto a = new int[n + 1];
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	deque<int> dq;
	for (int i = 1; i <= n; i++) {
		while (!dq.empty() && a[dq.back()] > a[i]) dq.pop_back();
		dq.push_back(i);
		cout << a[dq.front()] << ' ';
		if (!dq.empty() && i - l + 1 > 0 && dq.front() == i - l + 1) {
			dq.pop_front();
		}
	}
	delete[] a;
}