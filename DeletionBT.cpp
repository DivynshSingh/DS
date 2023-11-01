#include<iostream>
using namespace std;
class BinaryT{
struct node{
int data;
node* left;
node* right;
node(int data) : data(data), left(nullptr), right(nullptr){}
};
public:
node* root;
void insertion(int value){
    root=insertionRec(root, value);
}
void showIn(){
    showRec(root);
    cout<<endl;
}
void del(int value){
    root=deletionRec(root, value);
}
private:
node* insertionRec(node* current, int value){
if(current==nullptr){
    current=new node(value);
  }
if(current->data < value){
    current->right=insertionRec(current->right, value);
}
else if(current->data > value){
    current->left=insertionRec(current->left, value);
}
return current;
}
void showRec(node* current){
    if(current!=nullptr){
        cout<<current->data<<" ";
        showRec(current->left);
        showRec(current->right);
    }
}
node* findMin(node* current){
while(current->left != nullptr) {
current = current->left;
}
return current;
}
node* deletionRec(node* current, int value) {
if(current==nullptr){
    return current;
}
if(value<current->data) {
    current->left=deletionRec(current->left, value);
}else if(value>current->data) {
    current->right = deletionRec(current->right, value);
}else{
if(current->left == nullptr) {
    node* temp = current->right;
    delete current;
    return temp;
} else if (current->right == nullptr) {
    node* temp = current->left;
    delete current;
    return temp;
}
node* temp = findMin(current->right);
current->data = temp->data;
current->right = deletionRec(current->right, temp->data);
}
return current;
}
};
int main(){
BinaryT bt;
bt.insertion(0);
bt.insertion(2);
bt.insertion(8);
bt.insertion(1);
bt.insertion(5);
bt.showIn();
bt.del(5);
bt.del(9);
bt.showIn();
return 0;
}