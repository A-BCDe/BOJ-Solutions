#include <iostream>
#include <string>
#include <stack>
#include <deque>
using namespace std;
int main() {
	string s;
	cin >> s;
	stack<char> st;
	deque<char> dq;
	for (char c : s) {
		if (dq.size() != 4) {
			dq.push_back(c);
			continue;
		}
		if (dq.size() == 4 && dq[0] == 'P' && dq[1] == 'P' && dq[2] == 'A' && dq[3] == 'P') {
			dq.pop_back();
			dq.pop_back();
			dq.pop_back();
			dq.push_back(c);
			for (int i = 0; i < 2 && !st.empty(); i++) {
				dq.push_front(st.top());
				st.pop();
			}
			continue;
		}
		st.push(dq[0]);
		dq.pop_front();
		dq.push_back(c);
	}
	while (!dq.empty()) {
		if (dq.size() == 4 && dq[0] == 'P' && dq[1] == 'P' && dq[2] == 'A' && dq[3] == 'P') {
			dq.pop_back();
			dq.pop_back();
			dq.pop_back();
			for (int i = 0; i < 2 && !st.empty(); i++) {
				dq.push_front(st.top());
				st.pop();
			}
			continue;
		}
		st.push(dq.front());
		dq.pop_front();
	}
	if (st.size() != 1 || st.top() == 'A') {
		printf("NP");
	}
	else printf("PPAP");
}