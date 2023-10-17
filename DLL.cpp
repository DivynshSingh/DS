#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
    Node* prev;
};

Node* head = nullptr;

void insertAtPosition(int value, int position) {
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

void deleteAtPosition(int position) {
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

void displayList() {
    Node* current=head;
    while (current != nullptr) {
        cout<<current->data << " ";
        current=current->next;
    }
    cout<<endl;
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
