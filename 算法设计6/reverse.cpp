//��һ��
#include<iostream>
using namespace std;

string reverse(string s) {
    if (s.length() <= 1)
        return s;
    else
        return reverse(s.substr(1)) + s[0];
}
int main() {
    string s = "nihao";
    cout << "ԭ�ַ�����" << s << endl;
    cout << "���ú���ַ�����" << reverse(s) << endl;
    return 0;
}