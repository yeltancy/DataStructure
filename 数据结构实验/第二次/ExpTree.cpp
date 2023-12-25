#include<iostream>
#include<stack>;
#include<queue>;
#include <string>
using namespace std;

struct ETree {
	string data;
	ETree* lchild;
	ETree* rchild;
	ETree() :lchild(NULL), rchild(NULL) {};
	ETree(string d) {
		data = d;
		lchild = rchild = NULL;
	}
};
//�ж��ַ����Ƿ�Ϊ����
bool isNumeric(const std::string& str) {
    for (char c : str) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}
//ȥ�����пո�
string trimAll(string str) {
	int index = 0;
	if (!str.empty()) {
		while ((index = str.find(' ', index)) != string::npos) {
			str.erase(index, 1);
		}
	}
	return str;
}
//������׺���ʽ
string trans(string str1) {
    string str = trimAll(str1);
    string postexp;
    stack<char> opor;
    char c;
    int strLength = str.length();
    for (int i = 0; i < strLength; i++) {
        c = str[i];
        if (c == '=') {
            break;
        }
        else if (c == '(') {
            opor.push(c);
        }
        else if (c == ')') {
            while (!opor.empty() && opor.top() != '(') {
                postexp += opor.top();
                opor.pop();
            }
            opor.pop();
        }
        else if (c == '+' || c == '-') {
            while (!opor.empty() && opor.top() != '(') {
                postexp += opor.top();
                opor.pop();
            }
            opor.push(c);
        }
        else if (c == '*' || c == '/') {
            while (!opor.empty() && opor.top() != '(' && (opor.top() == '*' || opor.top() == '/')) {
                postexp += opor.top();
                opor.pop();
            }
            opor.push(c);
        }
        else {
            while (c >= '0' && c <= '9') {
                postexp += c;
                c = str[++i];
            }
            i--;
            postexp += '#';
        }
    }
    while (!opor.empty()) {
        postexp += opor.top();
        opor.pop();
    }
    return postexp;
}
class ExpressionTree {
public:
    ETree* root;
    ExpressionTree() {
        root = NULL;
    }
    // �������ʽ��
    void buildTree(string postfix) {
        int i = 0;
        char c;
        stack<ETree*> stack;
        int postfixLength = postfix.length();
        while (i < postfixLength) {
            c = postfix[i];
            if (isdigit(c)) {
                int d = 0;
                while (c >= '0' && c <= '9') {
                    d = 10 * d + (c - '0');
                    c = postfix[++i];
                }
                stack.push(new ETree(to_string(d)));
            }
            else {
                ETree* right = stack.top();
                stack.pop();
                ETree* left = stack.top();
                stack.pop();
                ETree* node = new ETree(string(1,c));
                //����һ���Ӽ��˳����ʽ��
                node->lchild = left;
                node->rchild = right;
                stack.push(node);
            }
            i++;
        }
        root = stack.top();
    }
    // ǰ�����
    void preOrder(ETree* node) {
        if (node != NULL) {
            cout << node->data;
            if (isNumeric(node->data)) {
                cout << "#";
            }
            preOrder(node->lchild);
            preOrder(node->rchild);
        }
    }
    //�������
    void inOrder(ETree* node){
        if (node != NULL) {
            inOrder(node->lchild);
            cout << node->data;
            if (isNumeric(node->data)) {
                cout << "#";
            }
            inOrder(node->rchild);
        }
    }
    //�������
    void postOrder(ETree* node){
        if (node != NULL) {
            postOrder(node->lchild);
            postOrder(node->rchild);
            cout << node->data; 
            if (isNumeric(node->data)) {
                cout << "#";
            }
        }
    }
    //��α���
    void levelOrder(ETree* root) {
        if (root == NULL) {
            return ;
        }
        queue<ETree*> q;
        q.push(root);
        while (!q.empty()) {
            ETree* node = q.front();
            q.pop();
            cout << node->data;
            if (isNumeric(node->data)) {
                cout << "#";
            }
            if (node->lchild != NULL) {
                q.push(node->lchild);
            }
            if (node->rchild != NULL) {
                q.push(node->rchild);
            }
        }
    }
    //������ʽֵ
    int getres(ETree* root) {
        if (root == NULL) {
            return 0;
        }
        if (isNumeric(root->data)) {
            return stoi(root->data);
        }
        int left = getres(root->lchild);
        int right = getres(root->rchild);
        if (root->data == "+") {
            return left + right;
        }
        else if (root->data == "-") {
            return left - right;
        }
        else if (root->data == "*") {
            return left * right;
        }
        else if (root->data == "/") {
            if (right != 0) {
                return left / right;
            }
            
        }
        return 0;
    }
};
int main() {
    //������׺���ʽ
    string str;
    getline(cin, str);
    string postfix = trans(str);
    //����������
    ExpressionTree tree;
    tree.buildTree(postfix);
    //ǰ�����
    tree.preOrder(tree.root);
    cout << endl;
    //�������
    tree.inOrder(tree.root);
    cout << endl;
    //�������
    tree.postOrder(tree.root);
    cout << endl;
    //��α���
    tree.levelOrder(tree.root);
    cout << endl;
    cout << tree.getres(tree.root);
}
 

