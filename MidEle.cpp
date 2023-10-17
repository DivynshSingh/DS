#include<iostream>
using namespace std;
struct Node{
int data;
Node* link;
};
void insert(Node** head, Node** it, int data){
    Node* newNode=new Node;
    newNode->data=data;
    newNode->link=nullptr;

    if(head==nullptr)*head=newNode;
    (*it)->link=newNode;
    (*it)=(*it)->link;;
}
void show(Node* head){
    if(head==nullptr)return;
    Node* it=head;
    while(it!=nullptr){
        cout<<it->data<<" ";
        it=it->link;
    }
}
void Inarray(Node* head, int arr[]){
    Node* it=head;
    arr[7];
    int i=0;
    while(it!=nullptr){
        arr[i]=it->data;
        it=it->link;
        i++;
    }
}
int main(){

struct Node* head=new Node;
head->data=0;
head->link=nullptr;
Node* it=head;
insert(&head, &it, 1);
insert(&head, &it, 2);
insert(&head, &it, 3);
insert(&head, &it, 4);
insert(&head, &it, 5);
insert(&head, &it, 6);
insert(&head, &it, 7);
show(head);
cout<<endl;
int arr[7];
Inarray(head, arr);
cout<<"the middle elemet is : "<<arr[(sizeof(arr)/sizeof(arr[0]))/2];
return 0;
}