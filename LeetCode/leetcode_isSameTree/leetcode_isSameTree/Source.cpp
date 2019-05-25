#include <iostream>
using namespace std;
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int data) : val(data), left(nullptr), right(nullptr) {}
};

bool isSameTree(TreeNode* p, TreeNode* q) {
	if (p == nullptr && q == nullptr) return true;
	if ((p == nullptr && q != nullptr) || (p != nullptr && q == nullptr)) return false;
	if (p->val != q->val)
		return false;
	else
		return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

int main() {
	TreeNode* pnode = new TreeNode(1);
	TreeNode* pnode1 = new TreeNode(2);
	TreeNode* pnode2 = new TreeNode(1);
	TreeNode* qnode = new TreeNode(1);
	TreeNode* qnode1 = new TreeNode(2);
	TreeNode* qnode2 = new TreeNode(3);
	pnode->left = pnode1;
	pnode->right = pnode2;
	qnode->left = qnode1;
	qnode->right = qnode2;
	bool res = isSameTree(pnode, qnode);
	cout << res << endl;
 	return 0;
}