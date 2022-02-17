#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;
vector<string> get_tree() {
	vector<string> v;
	while (true) {
		string s;
		cin >> s;
		if (s == "end") return v;
		v.emplace_back(move(s));
	}
}
struct node {
	node* left;
	node* right;
	string data;
	node(string data) : data(move(data)), left(nullptr), right(nullptr) {}
};
node* make_tree(vector<string> const& v, int &idx) {
	int const cur = idx;
	if (v[idx--] == "nil") return nullptr;
	auto n = new node(v[cur]);
	n->right = make_tree(v, idx);
	n->left = make_tree(v, idx);
	return n;
}
bool same_tree(node const* n1, node const* n2) {
	if (!n1 && !n2) return true;
	if (!n1 || !n2) return false;
	if (n1->data != n2->data) return false;
	if (same_tree(n1->left, n2->left) && same_tree(n1->right, n2->right)) return true;
	if (same_tree(n1->left, n2->right) && same_tree(n1->right, n2->left)) return true;
	return false;
}
int main() {
	int tt;
	cin >> tt;
	while (tt--) {
		auto v1 = get_tree();
		auto v2 = get_tree();
		int idx = v1.size()- 1;
		auto r1 = make_tree(v1, idx);
		idx = v2.size() - 1;
		auto r2 = make_tree(v2, idx);
		if (same_tree(r1, r2)) {
			printf("true\n");
		}
		else {
			printf("false\n");
		}
	}
}