#include<iostream>
#include<vector>
#include<sstream>
#include <algorithm>
#include<string>
using namespace std;


//sort()���Ƚϼ�ֵ���е�int����������
bool compare(const pair<string, int>& a, const pair<string, int>& b) {
    return a.second < b.second;
}
//�󵥸��ַ���������Ը���
int ROP(string str, int length) {
    int count = 0;
    for (int i = 0; i < length; i++) {
        for (int j = i + 1; j < length; j++) {
            if (str[i] > str[j]) {
                count++;
            }
        }
    }
    return count;
}
//������
vector<pair<string, int>> ReadAndOperate(int& length, int& num) {
    vector<pair<string, int>> strs;
    string str, numStr;
    //�����һ�е��ַ����������ַ�������
    getline(cin, str);
    istringstream ss(str);
    ss >> numStr;
    length = atoi(numStr.c_str());
    ss >> numStr;
    num = atoi(numStr.c_str());
    //��������ַ���
    while (getline(cin, str)) {
        //��ȡÿ���ַ���������Ը���
        int numOfROP = ROP(str, length);
        //���ַ���������Ը�����ɼ�ֵ�Դ���strs
        strs.push_back(make_pair(str, numOfROP));
    }
    return strs;
}
int main() {
    int length, num;
    vector<pair<string, int>> strs = ReadAndOperate(length, num);
    //�� ����Ը����������� ���ǰ� ������ൽ��С ����
    sort(strs.begin(), strs.end(), compare);
    //���string����
    for (int i = 0; i < num; i++) {
        cout << strs[i].first << endl;
    }
}