#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};
void addAt(Node **head, int position, int value){
Node* temp=new Node;
temp->data=value;
temp->next=nullptr;
if(position==1){
    temp->next=*head;
    *head=temp;
}
else{
Node* it=*head;
int i=2;
while(it->next!=nullptr && i!=position){
it=it->next;
i++;
}
temp->next=it->next;
it->next=temp;
}
}
void append(Node *head, int value){
    Node*it=head;
    while(it->next!=nullptr){
        it=it->next;
    }
    it->next=new Node;
    it->next->data=value;
    it->next->next=nullptr;
}
void show(Node* head){
    Node*it=head;
    while(it!=nullptr){
        cout<<it->data<<" ";
        it=it->next;
    }
    cout<<endl;
}
int main(){
    Node* head=new Node;
    head->data=1;
    head->next=nullptr;
    append(head, 2);
    append(head, 3);
    append(head, 4);
    int pos, value;
    show(head);
    cout<<"enter value and position where to add it "<<endl;
    cin>>value>>pos;
    addAt(&head, pos, value);
    cout<<"after addition :"<<endl;
    show(head);
    return 0;
}