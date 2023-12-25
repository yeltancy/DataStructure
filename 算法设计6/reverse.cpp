//第一题
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
    cout << "原字符串：" << s << endl;
    cout << "逆置后的字符串：" << reverse(s) << endl;
    return 0;
}