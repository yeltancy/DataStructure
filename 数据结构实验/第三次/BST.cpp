#include<iostream>
#include<sstream>
#include<vector>
#include <algorithm>
using namespace std;

struct BSTNode {
	int val;
	BSTNode* lchild;
	BSTNode* rchild;
	BSTNode(int val) {
		this->val = val;
		lchild = rchild = NULL;
	}
};
//������
vector<int> inputRead() {
    vector<int> nums;
    string str, numStr;
    while (getline(cin, str)) {
        istringstream ss(str);
        while (ss >> numStr) {
            int num = atoi(numStr.c_str());
            nums.push_back(num);
        }
    }
    //for (int i = 0; i < nums.size(); i++) {
    //    cout << nums[i] << " ";
    //}
    //cout << endl;
    return nums;
}

//�����ڵ�
BSTNode* insertNode(BSTNode* root, int val) {
    if (root == NULL) {
        root = new BSTNode(val);
    }
    else if (val < root->val) {
        root->lchild = insertNode(root->lchild, val);
    }
    else {
        root->rchild = insertNode(root->rchild, val);
    }
    return root;
}

//��������������
BSTNode* createBST(vector<int>& nums) {
    BSTNode* root = NULL;
    for (int i = 1; i < nums.size() - 1; i++) {
        root = insertNode(root, nums[i]);
    }
    return root;
}

//�������������Ҵ���
int searchBST(BSTNode* root, int key, int& count) {
    if (root == NULL) {
        return 0;
    }
    if (root->val == key) {
        count++;
        return count;
    }
    if (root->val > key) {
        count++;
        return searchBST(root->lchild, key, count);
    }
    else {
        count++;
        return searchBST(root->rchild, key, count);
    }
}

//�������
void inorderTraversal(BSTNode* root) {
    if (root != NULL) {
        inorderTraversal(root->lchild);
        cout << root->val << " ";
        inorderTraversal(root->rchild);
    }
}

//���ֲ��Ҵ���
int binarySearch(const vector<int>& inorderNums, int key) {
    int left = 0;
    int right = inorderNums.size() - 1;
    int count = 0;

    while (left <= right) {
        count++;
        int mid = left + (right - left) / 2;
        if (inorderNums[mid] == key) {
            return count;
        }
        else if (inorderNums[mid] < key) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    return -1; 
}

int main() {
    //������
    vector<int> nums = inputRead();
    //��������������
    BSTNode* root = createBST(nums);
    //���Ҷ���������
    int key = nums[nums.size() - 1];
    int count = 0;
    int BSTtimes = searchBST(root, key, count);
    cout << BSTtimes << endl;
    //�������
    inorderTraversal(root);
    cout << endl;
    //�������������������������򣩣�ֱ�������Ƶ�һ������
    vector<int> inorderNums(nums.begin() + 1, nums.end() - 1);
    sort(inorderNums.begin(), inorderNums.end());
    //���ַ�����
    int BStimes = binarySearch(inorderNums, key);
    cout << BStimes;
}


