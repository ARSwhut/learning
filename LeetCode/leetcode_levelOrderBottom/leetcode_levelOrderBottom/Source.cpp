#include <iostream>
#include <vector> 
#include <queue>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

vector<vector<int>> levelOrderBottom(TreeNode* root) {
	vector<vector<int>> res;
	queue<TreeNode*> que;
	if (root == nullptr) return res;
	que.push(root);
	TreeNode* tempNode = nullptr;
	while (!que.empty()) {
		vector<int> temp;
		int queNum = que.size();
		for (int i = 0; i < queNum; i++) {
			tempNode = que.front();
			que.pop();
			temp.push_back(tempNode->val);
			if (tempNode->left) {
				que.push(tempNode->left);
			}
			if (tempNode->right) {
				que.push(tempNode->right);
			}
		}
		res.push_back(temp);
	}
	reverse(res.begin(), res.end());
	return res;
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
	
	vector<vector<int>> res = levelOrderBottom(node);
	for (auto c : res) {
		for (auto item : c) {
			cout << item << " ";
		}
		cout << endl;
	}
	return 0;
}