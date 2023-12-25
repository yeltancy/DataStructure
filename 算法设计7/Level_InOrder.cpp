//µÚ°ËÌâ
#include<iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct TreeNode {
    char data;
    TreeNode* left, * right;
    TreeNode(char x) : data(x), left(NULL), right(NULL) {}
};

TreeNode* buildTree(vector<char>& level, vector<char>& in_order) {
    if (level.empty())
        return NULL;

    TreeNode* root = new TreeNode(level[0]);

    vector<char>::iterator rootPos = find(in_order.begin(), in_order.end(), level[0]);
    vector<char> left_in_order(in_order.begin(), rootPos);
    vector<char> right_in_order(rootPos + 1, in_order.end());

    vector<char> left_level, right_level;
    for (int i = 1; i < level.size(); i++) {
        vector<char>::iterator pos = find(in_order.begin(), in_order.end(), level[i]);
        if (pos < rootPos)
            left_level.push_back(level[i]);
        else
            right_level.push_back(level[i]);
    }

    root->left = buildTree(left_level, left_in_order);
    root->right = buildTree(right_level, right_in_order);

    return root;
}
