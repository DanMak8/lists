#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* next;
    Node* prev;

    Node(int val) : value(val), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    void addToHead(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = tail = newNode;
        }
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

 
    void addToTail(int value) {
        Node* newNode = new Node(value);
        if (tail == nullptr) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void remove(int value) {
        Node* current = head;
        while (current != nullptr) {
            if (current->value == value) {
                if (current->prev != nullptr) {
                    current->prev->next = current->next;
                }
                else {
                    head = current->next;
                }
                if (current->next != nullptr) {
                    current->next->prev = current->prev;
                }
                else {
                    tail = current->prev;
                }
                delete current;
                return;
            }
            current = current->next;
        }
    }

    void print() const {
        Node* current = head;
        while (current != nullptr) {
            cout << current->value << " ";
            current = current->next;
        }
        cout << endl;
    }

    ~DoublyLinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }
};

int main() {
    setlocale(LC_ALL, "RUS");
    DoublyLinkedList list;

    list.addToHead(10);
    list.addToHead(20);
    list.addToTail(30);
    list.addToTail(40);

    cout << "Содержимое списка: ";
    list.print();

    list.remove(10);
    cout << "После удаления 10: ";
    list.print();

    return 0;
}
