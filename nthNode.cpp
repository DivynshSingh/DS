#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};

void insertAtEnd(Node*& head, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    } else {
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
}
int total(Node* head){
    Node* current=head;
    int total=0;
    while(current!=nullptr){
        total++;
        current=current->next;
    }
    return total;
}
void printNthNode(Node* head, int n) {
    int count = 0;
    Node* current = head;

    while (current != nullptr) {
        if (count == n) {
            std::cout << "Node " << n << " from the end is: " << current->data << std::endl;
            return;
        }
        current = current->next;
        count++;
    }

}

int main() {
    Node* head = nullptr;

    for (int i = 1; i <= 5; i++) {
        insertAtEnd(head, i);
    }

    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    printNthNode(head, total(head)-n);

    Node* current = head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}
