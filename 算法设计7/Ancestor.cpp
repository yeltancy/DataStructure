//�ڶ���
#include<iostream>
using namespace std;

void AllAncestor(char b[], int i) {
    if (i == 0 || i > strlen(b)) {
        cout << "��Ŵ���" << endl;
        return;
    }
    while (i > 1) {
        i = i / 2;
        cout << "���Ƚڵ��У�" << i << ":" << b[i] << endl;
    }
}
int main() {
    char b[] = "#ABCDEFGHIJK###";
    AllAncestor(b, 20);
}