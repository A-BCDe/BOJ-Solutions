#include <stdio.h>
#include <queue>
using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	priority_queue<int> left, right;
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		left.push(x);
		x = left.top();
		left.pop();
		right.push(-x);
		x = -right.top();
		right.pop();
		if (left.size() == right.size()) left.push(x);
		else right.push(-x);
		printf("%d\n", left.top());
	}
}