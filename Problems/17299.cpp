#include <stdio.h>
#include <stack>
int main() {
	int n;
	scanf("%d", &n);
	auto a = new int[n];
	auto res = new int[n];
	std::fill(res, res + n, -1);
	auto f = new int[1000001]();
	std::stack<int> s;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		f[a[i]]++;
	}
	for (int i = 0; i < n; i++) {
		while (!s.empty() && f[a[s.top()]] < f[a[i]]) {
			res[s.top()] = a[i];
			s.pop();
		}
		s.push(i);
	}
	for (int i = 0; i < n; i++) {
		printf("%d ", res[i]);
	}
}