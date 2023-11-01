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
    displayList(head);

    deleteAtStart(&head);
    deleteAtStart(&head);
    displayList(head);

    return 0;
}