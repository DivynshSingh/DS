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
};
int main(){
BinaryT bt;
bt.insertion(0);
bt.insertion(2);
bt.insertion(8);
bt.insertion(1);
bt.insertion(5);
bt.showIn();
return 0;
}