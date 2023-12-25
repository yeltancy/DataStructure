//µÚÎåÌâ
#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};
void delx(Node*& p, int x) {
    if (p == nullptr) { 
        return;
    }
    if (p->data == x) { 
        Node* temp = p;
        p = p->next;
        delete temp;
        return;
    }
    delx(p->next, x); 
}

int main() {
    Node* p = new Node;
    p->data = 1;
    p->next = nullptr;
    Node* newNode = new Node;
    newNode->data = 2;
    newNode->next = nullptr;
    p->next = newNode;
    newNode = new Node;
    newNode->data = 3;
    newNode->next = nullptr;
    p->next->next = newNode;
    delx(p, 2); 
    Node* cur = p;
    while (cur != nullptr) {
        cout << cur->data << " ";
        cur = cur->next;
    }
    return 0;
}