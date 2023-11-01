#include<iostream>
using namespace std;
struct Node{
int data;
Node* next;
// Node(int data) : data(data), next(nullptr){}
};
void append(Node* head, int value){
    Node* it=head;
    while(it->next!=nullptr){
        it=it->next;
    }
    it->next=new Node;//(value);
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
void search(Node* head, int s){
Node* it=head;
int count=1;
while(it!=nullptr){
    if((it->data)==s){
        cout<<"element found in the list at position: "<<count<<endl;
        return;
    }
    count++;
    it=it->next;
}
cout<<"element not found"<<endl;
}
int main(){
Node* head=new Node;//(0);
head->data=0;
head->next=nullptr;
append(head, 1);
append(head, 2);
append(head, 3);
append(head, 4);
show(head);
cout<<" Enter element to search: "<<endl;
int s;
cin>>s;
search(head, s);
return 0;
}