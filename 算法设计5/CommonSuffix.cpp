//第五题
#include<iostream>
using namespace std;

struct Node {
    char data;
    Node* next;
    Node(char value) : data(value), next(nullptr) {}
};
class LinkedList {
public:
    LinkedList() : head(nullptr) {}
    void insert(char value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
        }
        else {
            Node* current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = newNode;
        }
    }
    // 倒置链表
    void reverse() {
        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;

        while (current) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        head = prev;
    }
    void print() {
        Node* current = head;
        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
    Node* head;
};

char commonSuffix(LinkedList* List1, LinkedList* List2) {
    List1->reverse();
    List2->reverse();
    Node* list1 = List1->head;
    Node* list2 = List2->head;
    while ((list1->next != NULL) && (list2->next != NULL)) {
        if (list1->next->data == list2->next->data) {
            list1 = list1->next;
            list2 = list2->next;
        }
        else {
            break;
        }
    }
    return list1->data;
}
int main() {
    LinkedList List1;
    List1.insert('l');
    List1.insert('o');
    List1.insert('a');
    List1.insert('d');
    List1.insert('i');
    List1.insert('n');
    List1.insert('g');
    LinkedList List2;
    List2.insert('b');
    List2.insert('e');
    List2.insert('i');
    List2.insert('n');
    List2.insert('g');
    char a = commonSuffix(&List1, &List2);
    cout << a << endl;
    
}
