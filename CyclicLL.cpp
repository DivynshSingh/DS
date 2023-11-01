#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
    Node(int data) : data(data), next(nullptr) {}
};

void insert(Node*& head, int data) {
    Node* newNode = new Node(data);
    if (!head) {
        head = newNode;
        newNode->next = head;
    } else {
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }
}

void display(Node* head) {
    Node* temp = head;
    if (head) {
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;

    insert(head, 1);
    insert(head, 2);
    insert(head, 3);
    insert(head, 4);
    insert(head, 5);

    cout << "Circular Linked List: ";
    display(head);

    return 0;
}
