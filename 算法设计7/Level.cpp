//µÚÒ»Ìâ
#include<iostream>
using namespace std;

int Level(char b[], int i) {
    if (i == 0 || i > strlen(b)) {
        return 0;
    }
    int level = 1; 
    while (i > 1) {
        i = i / 2; 
        level++;
    }
    return level;
}
