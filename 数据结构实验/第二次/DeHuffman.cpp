#include<iostream>
#include<fstream>
using namespace std;

typedef struct ETree {
    char data;
    ETree* lchild;
    ETree* rchild;
    ETree() :lchild(NULL), rchild(NULL) {};
    ETree(char d) {
        data = d;
        lchild = rchild = NULL;
    }
}TreeNode;

// 创建节点
TreeNode* createNode(TreeNode* node, char i) {
    switch (i) {
    case '0':
        if (node->lchild == NULL) {
            node->lchild = new TreeNode();
        }
        node = node->lchild;
        break;
    case '1':
        if (node->rchild == NULL) {
            node->rchild = new TreeNode();
        }
        node = node->rchild;
        break;
    }
    return node;
}

// 创建树
void createTree(TreeNode* root) {
    int codeNum;
    cin >> codeNum;
    for (int i = 0; i < codeNum; i++) {
        TreeNode* temp = root;
        char c1, c2;
        string str;
        cin >> c1 >> c2;
        cin >> str;
        for (int j = 0; j < str.size(); j++) {
            temp = createNode(temp, str[j]);
        }
        temp->data = c1;
    }
}

int main() {
    TreeNode* root = new TreeNode();
    // 创建树
    createTree(root);
    //打开文件
    ifstream file;
    file.open("in.txt");
    if (!file.is_open()) {
        cerr << "文件打开错误" << endl;
        return 1;
    }
    string codes;
    while (!file.eof()) {      
        file >> codes;
    }
    //关闭文件
    file.close();
    // 开始解码
    TreeNode* temp = root;
    for (int i = 0; i < codes.size(); i++) {
        switch (codes[i]) {
        case '1':
            temp = temp->rchild;
            break;
        case '0':
            temp = temp->lchild;
            break;
        }
        if (temp->data) {
            cout << temp->data;
            temp = root;
        }
    }
}
