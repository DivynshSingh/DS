#include<iostream>
using namespace std;


struct Node{
int data;
Node* left;
Node* right;
Node(int value) : data(value), left(nullptr), right(nullptr){}
};

class BinaryTree{
Node* root;

public:
BinaryTree() : root(nullptr){}

void insert(int value){
    root=InsertRecursive(root, value);
}

void PostOrderTraversal(){
    PostOrderTraversalRecursive(root);
}

private:
Node* InsertRecursive(Node* current, int value){
    if(current==nullptr){
        return new Node(value);
    }
    if(value < current->data){
        current->left=InsertRecursive(current->left, value);
    }
    else if(value > current->data)current->right=InsertRecursive(current->right, value);
return current;
}

void PostOrderTraversalRecursive(Node* current){
    if(current==nullptr)return;
    PostOrderTraversalRecursive(current->left);
    PostOrderTraversalRecursive(current->right);
    cout<<current->data<<" ";
}
};
int main(){
BinaryTree BT;
BT.insert(7);
BT.insert(101);
BT.insert(14);
BT.insert(124);
BT.insert(24);
cout<<" Post-Order traversal: ";
BT.PostOrderTraversal();
}