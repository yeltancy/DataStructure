//第二题
#include<iostream>
using namespace std;

void AllAncestor(char b[], int i) {
    if (i == 0 || i > strlen(b)) {
        cout << "编号错误" << endl;
        return;
    }
    while (i > 1) {
        i = i / 2;
        cout << "祖先节点有：" << i << ":" << b[i] << endl;
    }
}
int main() {
    char b[] = "#ABCDEFGHIJK###";
    AllAncestor(b, 20);
}