#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};

void insertAtStart(Node** head, int value) {
    Node* newNode=new Node;
    newNode->data=value;
    newNode->next=*head;
    *head=newNode;
}

void deleteAtStart(Node** head) {
    if (*head==nullptr) {
        return;
    }
    Node* temp=*head;
    *head=(*head)->next;
    delete temp;
}

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

    insertAtStart(&head, 3);
    insertAtStart(&head, 2);
    insertAtStart(&head, 1);
    insertAtEnd(&head, 4);
    insertAtEnd(&head, 5);

    displayList(head);

    deleteAtStart(&head);
    deleteAtEnd(&head);

    displayList(head);

    return 0;
}
