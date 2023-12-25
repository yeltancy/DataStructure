//µÚÁùÌâ
#include<iostream>
#include<queue>
using namespace std;

struct BTNode {
	char data;
	BTNode* left, * right;
	BTNode(char x) : data(x), left(NULL), right(NULL) {}
};

struct TreeNode{
	int lev;
	BTNode* node;
	TreeNode(int lev, BTNode* node):lev(1),node(node){}
};

int KCount(BTNode& bt,int k) {
	int count = 0;
	queue<TreeNode> qu;
	qu.push(TreeNode(1, bt.left));
	while (!qu.empty()) {
		TreeNode t = qu.front(); qu.pop();
		if (t.lev > k) {
			return count;
		}
		if (t.lev == k) {
			count++;
		}
		else {
			if (t.node->left != NULL) {
				qu.push(TreeNode(t.lev + 1, t.node->left));
			}
			if (t.node->right != NULL) {
				qu.push(TreeNode(t.lev + 1, t.node->right));
			}
		}
	}
	return count;
}

int getWidth(BTNode& bt,int lev) {
	int maxWidth = 0;
	int k = 1;
	while (k <= lev) {
		int tem = KCount(bt, k);
		k++;
		maxWidth = (maxWidth >= tem) ? maxWidth : tem;
	}
	return maxWidth;
}