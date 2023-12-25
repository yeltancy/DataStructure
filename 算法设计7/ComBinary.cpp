//µÚÆßÌâ
#include<iostream>
#include <queue>
using namespace std;

struct BTNode {
    char data;
    BTNode* left, * right;
    BTNode(char x) : data(x), left(NULL), right(NULL) {}
};

bool isCompleteBT(BTNode* root) {
    if (root == NULL)
        return true;
    queue<BTNode*> q;
    q.push(root);
    bool flag = false;
    while (!q.empty()) {
        BTNode* temp = q.front();
        q.pop();

        if (temp->left) {
            if (flag == true)
                return false;
            q.push(temp->left);
        }
        else
            flag = true;

        if (temp->right) {
            if (flag == true)
                return false;
            q.push(temp->right);
        }
        else
            flag = true;
    }
    return true;
}
