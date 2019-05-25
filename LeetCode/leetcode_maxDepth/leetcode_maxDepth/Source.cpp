#include <iostream>
#define max(a, b) (a > b) ? (a) : (b)
using namespace std;
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int maxDepth(TreeNode* root) {
	/*if (root == nullptr) return 0;
	int lDepth = 1 + maxDepth(root->left);
	int rDepth = 1 + maxDepth(root->right);
	return max(lDepth, rDepth);*/
	if (root == nullptr) return 0;
	return max((1 + maxDepth(root->left)), (1 + maxDepth(root->right)));
}

int main() {
	TreeNode* node = new TreeNode(3);
	TreeNode* node1 = new TreeNode(9);
	TreeNode* node2 = new TreeNode(20);
	TreeNode* node3 = new TreeNode(15);
	TreeNode* node4 = new TreeNode(7);
	node->left = node1;
	node->right = node2;
	node2->left = node3;
	node2->right = node4;
	int depth = maxDepth(node);
	cout << depth << endl;
	return 0;
}