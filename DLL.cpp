#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

void insertAtPosition(Node*& head, int value, int position) {
    if (position < 0) return;

    Node* newNode = new Node;
    newNode->data = value;

    if (position == 0) {
        newNode->next = head;
        newNode->prev = nullptr;
        if (head != nullptr) head->prev = newNode;
        head = newNode;
        return;
    }

    Node* current = head;
    int count = 0;
    while (current != nullptr && count < position - 1) {
        current = current->next;
        count++;
    }

    if (current == nullptr) return;

    newNode->next = current->next;
    newNode->prev = current;
    if (current->next != nullptr) current->next->prev = newNode;
    current->next = newNode;
}

void deleteAtPosition(Node*& head, int position) {
    if (position < 0 || head == nullptr) return;
    if (position == 0) {
        Node* temp = head;
        head = head->next;
        if (head != nullptr) head->prev = nullptr;
        delete temp;
        return;
    }

    Node* current = head;
    int count = 0;
    while (current != nullptr && count < position - 1) {
        current = current->next;
        count++;
    }

    if (current == nullptr || current->next == nullptr) return;
    Node* temp = current->next;
    current->next = current->next->next;
    if (current->next != nullptr) current->next->prev = current;
    delete temp;
}

void show(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;
    insertAtPosition(head, 1, 0);
    insertAtPosition(head, 2, 1);
    insertAtPosition(head, 3, 2);
    insertAtPosition(head, 4, 0);

    show(head);

    deleteAtPosition(head, 1);

    show(head);

    return 0;
}
