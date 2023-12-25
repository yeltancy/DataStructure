//第一题
#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* next;
    Node(char d) : data(d), next(NULL) {}
};
class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}
    void append(char data) {
        if (!head) {
            head = new Node(data);
            return;
        }
        Node* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = new Node(data);
    }
    int longestPlatform() {
        if (!head) {
            return 0;
        }
        int maxPlatform = 1;
        int currentPlatform = 1;
        Node* current = head;
        while (current->next) {
            if (current->data == current->next->data) {
                currentPlatform++;
            }
            else {
                if (currentPlatform > maxPlatform) {
                    maxPlatform = currentPlatform;
                }
                currentPlatform = 1;
            }
            current = current->next;
        }

        if (currentPlatform > maxPlatform) {
            maxPlatform = currentPlatform;
        }

        return maxPlatform;
    }
};
int main() {
    LinkedList s;
    s.append('a');
    s.append('a');
    s.append('b');
    s.append('b');
    s.append('b');
    s.append('c');
    s.append('c');
    s.append('c');
    s.append('c');
    s.append('a');
    s.append('a');
    s.append('a');
    int result = s.longestPlatform();
    cout << "最长平台的长度为：" << result << endl;
    return 0;
}
