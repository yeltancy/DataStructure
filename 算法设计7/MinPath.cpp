//µÚÎåÌâ
#include<iostream>
#include <algorithm>
using namespace std;

struct BTNode {
	char data;
	BTNode* left, * right;
	BTNode(char x) : data(x), left(NULL), right(NULL) {}
};
int getPath(BTNode* root) {
    if (root == nullptr) {
        return 0;
    }
    if (root->left == nullptr && root->right == nullptr) {
        return 1;
    }
    if (root->left == nullptr) {
        return 1 + getPath(root->right);
    }
    if (root->right == nullptr) {
        return 1 + getPath(root->left);
    }
    return 1 + min(getPath(root->left), getPath(root->right));
}