#include <stdio.h>
#include <stdlib.h>
struct node {
	int data;
	node* left, * right;
};
void make(int n, int const* pre, int pre_idx, int const* in, int in_begin, int in_end, node** root) {
	if (in_begin == in_end) return;
	*root = (node*)malloc(sizeof(node));
	(*root)->data = pre[pre_idx];
	(*root)->left = nullptr;
	(*root)->right = nullptr;
	for (int i = in_begin; i != in_end; i++) {
		if (in[i] == pre[pre_idx]) {
			make(n, pre, pre_idx + 1, in, in_begin, i, &(*root)->left);
			pre_idx += i - in_begin;
			make(n, pre, pre_idx + 1, in, i + 1, in_end, &(*root)->right);
			break;
		}
	}
	return;
}
void dfs(node* root) {
	if (!root) return;
	dfs(root->left);
	dfs(root->right);
	printf("%d ", root->data);
}
void destruct(node** root) {
	if ((*root)->left) destruct(&(*root)->left);
	if ((*root)->right) destruct(&(*root)->right);
	free(*root);
}
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		int* pre = (int*)malloc(sizeof(int) * n);
		int* in = (int*)malloc(sizeof(int) * n);
		for (int i = 0; i < n; i++) scanf("%d", &pre[i]);
		for (int i = 0; i < n; i++) scanf("%d", &in[i]);
		node* root;
		make(n, pre, 0, in, 0, n, &root);
		dfs(root); printf("\n");
		destruct(&root);
		free(pre);
		free(in);
	}
}