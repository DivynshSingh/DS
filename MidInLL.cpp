#include<iostream>
using namespace std;
struct Node{
int data;
Node* next;
};
void append(Node* head, int value){
    Node* it=head;
    while(it->next!=nullptr){
        it=it->next;
    }
    it->next=new Node;
    it->next->data=value;
    it->next->next=nullptr;
}
void show(Node* head) {
    Node* current=head;
    while(current!=nullptr) {
        cout<<current->data << " ";
        current=current->next;
    }
    cout<<endl;
}
Node* MiddleInLL(Node* head){
if (head == nullptr) {
        return nullptr;
    }

    Node* slow = head;
    Node* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;

}
int main(){
Node* head=new Node;
head->data=0;
head->next=nullptr;
append(head, 1);
append(head, 2);
append(head, 3);
append(head, 4);
show(head);
cout<<MiddleInLL(head)->data;
return 0;
}