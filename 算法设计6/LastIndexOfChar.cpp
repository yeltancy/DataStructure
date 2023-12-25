//第二题
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
        cout << "字符'" << c << "'在字符串中的最后一个位置是：" << position << endl;
    else
        cout << "字符'" << c << "'在字符串中没有找到。" << endl;
    return 0;
}