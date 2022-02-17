#include <iostream>
#include <set>
#include <string>
#include <stack>
#include <vector>
#include <utility>
using namespace std;

void dfs(string const& s, vector<pair<int, int>> const& v, vector<bool>& b, set<string>& vs) {
	if (b.size() == v.size()) {
		bool flag = false;
		for (auto bb : b) {
			if (bb == false) { flag = true; break; }
		}
		if (!flag) return;
		string str;
		for (int i = 0; i < s.size(); i++) {
			flag = false;
			for (int j = 0; j < v.size(); j++) {
				if (!b[j] && (v[j].first == i || v[j].second == i)) { flag = true; break; }
			}
			if (flag) continue;
			str += s[i];
		}
		if (vs.find(str) == vs.end()) vs.insert(move(str));
		return;
	}
	b.push_back(true);
	dfs(s, v, b, vs);
	b[b.size() - 1] = false;
	dfs(s, v, b, vs);
	b.pop_back();
}

int main() {
	string s;
	cin >> s;
	auto const len = s.length();
	stack<int> st;
	vector<pair<int, int>> v;
	for (int i = 0; i < len; i++) {
		if (s[i] == '(') {
			st.push(i);
		}
		else if (s[i] == ')') {
			v.emplace_back(st.top(), i);
			st.pop();
		}
	}
	vector<bool> b;
	set<string> vs;
	dfs(s, v, b, vs);
	for (auto const& now : vs) {
		cout << now << endl;
	}
}