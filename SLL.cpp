#include <iostream>

struct Node {
    int data;
    Node* next;
};

Node* head = nullptr;

void insertAtPosition(int value, int position) {
    Node* newNode = new Node;
    newNode->data = value;

    if (position == 0) {
        newNode->next = head;
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
    current->next = newNode;
}

void deleteAtPosition(int position) {
    if (position < 0 || head == nullptr) return;

    if (position == 0) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* current = head;
    int count = 0;
    while (current != nullptr && count < position - 1) {
        current = current->next;
        count++;
    }

    if (current == nullptr || current->next == nullptr) return; // Invalid position

    Node* temp = current->next;
    current->next = current->next->next;
    delete temp;
}

void displayList() {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

int main() {
    insertAtPosition(1, 0);
    insertAtPosition(2, 1);
    insertAtPosition(3, 2);

    displayList();

    deleteAtPosition(1);

    displayList();

    return 0;
}
