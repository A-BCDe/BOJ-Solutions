#include <stdio.h>
#include <deque>
#include <utility>
using namespace std;
struct str {
	int min;
	int max;
	int idx;
};
void cleanup(deque<str>& dq) {
	str s;
A:
	s = move(dq.back());
	dq.pop_back();
	if (s.max + 1 == dq.back().min) {
		printf("%d\n", dq.back().idx);
		dq.back().idx = s.idx;
		dq.back().min = s.min;
		goto A;
	}
	else if (s.min - 1 == dq.back().max) {
		printf("%d\n", dq.back().idx);
		dq.back().idx = s.idx;
		dq.back().max = s.max;
		goto A;
	}
	else {
		dq.emplace_back(move(s));
	}
}
int main() {
	int n;
	scanf("%d", &n);
	deque<str> dq;
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		auto s = str{ x, x, i + 1 }; // min, max, idx
		if (dq.empty()) {
			dq.emplace_back(move(s));
		}
		if (x + 1 == dq.back().min) {
			printf("%d\n", dq.back().idx++);
			dq.back().min = x;
			cleanup(dq);
		}
		else if (x - 1 == dq.back().max) {
			printf("%d\n", dq.back().idx++);
			dq.back().max = x;
			cleanup(dq);
		}
		else {
			dq.emplace_back(move(s));
		}
	}
}