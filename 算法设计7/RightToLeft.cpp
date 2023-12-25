//µÚÈıÌâ
#include<iostream>
using namespace std;

struct TreeNode {
	char data; 
	TreeNode* left, * right;
	TreeNode(char x) : data(x), left(NULL), right(NULL) {} 
};

void printLeaves(TreeNode* root) {
	if (root == NULL) return; 
	if (root->right) printLeaves(root->right); 
	if (root->left == NULL && root->right == NULL) cout << root->data << " "; 
	if (root->left) printLeaves(root->left); 
}
