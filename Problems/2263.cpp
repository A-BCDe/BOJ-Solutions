#include <stdio.h>
#include <vector>
using namespace std;
struct node { int data; node* left; node* right; node(int data, node* left = nullptr, node* right = nullptr) : data(data), left(left), right(right) {} };
node* f(int* mid, int* mid_idx, int* pos, int n, int l, int r) {
	if (l == r) return nullptr;
	int i = mid_idx[pos[n - 1]];
	auto right = f(mid, mid_idx, pos, n - 1, i + 1, r);
	auto left = f(mid, mid_idx, pos, n - 1 - r + i + 1, l, i);
	auto nd = new node(pos[n - 1], left, right);
	return nd;
}
void fwd(node* n) {
	if (n == nullptr) return;
	printf("%d ", n->data);
	fwd(n->left);
	fwd(n->right);
}
int main() {
	int n;
	scanf("%d", &n);
	auto mid = new int[n];
	auto mid_idx = new int[n + 1];
	auto pos = new int[n];
	for (int i = 0; i < n; i++) {
		scanf("%d", &mid[i]);
		mid_idx[mid[i]] = i;
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &pos[i]);
	}
	auto nd = f(mid, mid_idx, pos, n, 0, n);
	fwd(nd);
	

	delete[] mid;
	delete[] mid_idx;
	delete[] pos;
}