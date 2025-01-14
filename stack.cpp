#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* next;

    Node(int val) : value(val), next(nullptr) {}
};

class Stack {
private:
    Node* topNode;

public:
    Stack() : topNode(nullptr) {}

    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = topNode;
        topNode = newNode;
    }

    void pop() {
        if (topNode == nullptr) {
            cout << "���� ����, ������ ������� �������." << endl;
            return;
        }
        Node* temp = topNode;
        topNode = topNode->next;
        delete temp;
    }

    int top() const {
        if (topNode == nullptr) {
            cout << "���� ����." << endl;
            return -1;
        }
        return topNode->value;
    }

    bool isEmpty() const {
        return topNode == nullptr;
    }

    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }
};

/*int main() {
    Stack stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    cout << "������� ������� �����: " << stack.top() << endl;

    stack.pop();
    cout << "����� �������� �������� ��������, ����� ������� �������: " << stack.top() << endl;

    stack.pop();
    stack.pop();
    stack.pop();

    return 0;
}*/
