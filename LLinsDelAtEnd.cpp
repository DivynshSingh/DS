#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};
void insertAtEnd(Node** head, int value) {
    Node* newNode=new Node;
    newNode->data=value;
    newNode->next=nullptr;

    if (*head==nullptr) {
        *head=newNode;
    } else {
        Node* current=*head;
        while(current->next!=nullptr) {
            current=current->next;
        }
        current->next=newNode;
    }
}

void deleteAtEnd(Node** head) {
    if (*head==nullptr) {
        return;
    }

    if ((*head)->next==nullptr) {
        delete *head;
        *head=nullptr;
        return;
    }

    Node* current=*head;
    while(current->next->next != nullptr){
        current=current->next;
    }
    
    delete current->next;
    current->next=nullptr;
}

void displayList(Node* head) {
    Node* current=head;
    while(current!=nullptr) {
        cout<<current->data << " ";
        current=current->next;
    }
    cout<<endl;
}

int main() {
    Node* head = nullptr;

    insertAtEnd(&head, 4);
    insertAtEnd(&head, 5);
    insertAtEnd(&head, 6);
    insertAtEnd(&head, 7);

    displayList(head);

    deleteAtEnd(&head);
    deleteAtEnd(&head);

    displayList(head);

    return 0;
}
