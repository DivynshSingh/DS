#include<iostream>
using namespace std;
struct Node{
int data;
Node* link;
Node(int value) : data(value), link(nullptr){}
};
void add(Node** head, Node*& it, int value){
    Node* NewNode=new Node(value);
    if(head==nullptr){
        *head=NewNode;
    }
    else{
    it->link=NewNode;
    it=NewNode;}

};
void show(Node* head){
    Node* current=head;
    while(current !=nullptr){
        std::cout<<current->data<<" ";
        current=current->link;
    }
}
void reverse(Node **head){
    Node *a,*b,*c;
    a=*head;
    b=a->link;
    c=b->link;
    a->link=nullptr;
    while(c!=nullptr){
        b->link=a;
        a=b;
        b=c;
        c=c->link;
    }
    b->link=a;
    *head=b;
}
void reverse(Node*& head){
Node* current = head;
int count=0;
while(current != nullptr){
count++;
current=current->link;
}
current = head;
int arr[count];
int i=0;
while(current!=nullptr){
arr[i]=current->data;
current=current->link;
i++;
}
i--;
current = head;
while(current!=nullptr && i>=0){
current->data=arr[i];
current=current->link;
i--;
}
}
int main(){
    // Node* head=(Node*)malloc(sizeof(Node));//not recommended in cpp this part caused some problme earlier too, would not reverse LL correctly
    Node* head=new Node(0);
    Node* it=head; //"it" keeps track of last node, which helps in appending element at end with o(1) complexity
    add(&head, it, 1);
    add(&head, it, 2);
    add(&head, it, 3);
    add(&head, it, 4);
    cout<<"Original list: ";
    show(head);
    cout<<endl;
    reverse(&head);
    cout<<"Reversed list: ";
    show(head);
    cout<<endl;
    cout<<"Reversing the list again: ";
    reverse(head);
    show(head);
    return 0;
}