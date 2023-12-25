//第四题
#include<iostream>
using namespace std;

struct Node {
    char data;
    Node* next;
};

int non_repeat(Node* s, Node* t) {
    if (s == nullptr || t == nullptr) {
        return 0;
    }
    if (s->data == t->data) {
        Node* sPtr = s;
        Node* tPtr = t;
        while (sPtr != nullptr && tPtr != nullptr && sPtr->data == tPtr->data) {
            sPtr = sPtr->next;
            tPtr = tPtr->next;
        }
        if (tPtr == nullptr) {
            return 1 + non_repeat(sPtr, t);
        }
    }
    return non_repeat(s->next, t);
}

int main() {
    Node* s = new Node{'a', new Node{'a', new Node{'b', new Node{'a', new Node{'b', new Node{'a', new Node{'d', nullptr}}}}}}};
    Node* t = new Node{'a', new Node{'b', new Node{'a', nullptr}}};
    int result = non_repeat(s, t);
    cout << "t在s中不重叠出现的次数为: " << result << endl;
    Node* temp;
    while (s != nullptr) {
        temp = s;
        s = s->next;
        delete temp;
    }
    while (t != nullptr) {
        temp = t;
        t = t->next;
        delete temp;
    }
    return 0;
}
