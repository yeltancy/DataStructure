//�ڶ���
#include<iostream>
using namespace std;

int lastIndexOfChar(string s, char c, int index = 0, int position = -1){
    if (index == (int)s.length())
        return position;
    else {
        if (s[index] == c)
            position = index;
        return lastIndexOfChar(s, c, index + 1, position);
    }
}
int main() {
    string s = "hello,world";
    char c = 'o';
    int position = lastIndexOfChar(s, c);
    if (position != -1)
        cout << "�ַ�'" << c << "'���ַ����е����һ��λ���ǣ�" << position << endl;
    else
        cout << "�ַ�'" << c << "'���ַ�����û���ҵ���" << endl;
    return 0;
}