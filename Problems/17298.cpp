#include <stdio.h>
#include <stack>
#include <utility>
using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	auto a = new int[n];
	auto res = new int[n];
	stack<int> s;
	fill(res, res + n, -1);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		while (!s.empty() && a[s.top()] < a[i]) {
			res[s.top()] = a[i];
			s.pop();
		}
		s.push(i);
	}
	for (int i = 0; i < n; i++) {
		printf("%d ", res[i]);
	}
}