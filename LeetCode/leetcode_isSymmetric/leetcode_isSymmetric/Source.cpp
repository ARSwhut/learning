#include <iostream>
using namespace std;
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
bool ismirror(TreeNode* p, TreeNode* q) {
	if (p == nullptr)
		return q == nullptr;
	else if (q == nullptr)
		return q == nullptr;
	else if (p->val == q->val) {
		return ismirror(p->left, q->right) && ismirror(p->right, q->left);
	}
	else {
		return false;
	}
}
bool isSymmetric(TreeNode* root) {
	return ismirror(root, root);
}