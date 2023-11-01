#include <iostream>
using namespace std;
class BinaryTree {
struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};
public:
    BinaryTree() : root(nullptr) {}

    void insert(int value){
        root=insertRecursive(root, value);
    }

    void PreOrderTraversal(){
        PreOrderTraversalRecursive(root);
    }

private:
    Node* root;

    Node* insertRecursive(Node* current, int value) {
        if (current==nullptr) {
            return new Node(value);
        }

        if (value < current->data) {
            current->left = insertRecursive(current->left, value);
        } else if (value > current->data) {
            current->right = insertRecursive(current->right, value);
        }

        return current;
    }
    void PreOrderTraversalRecursive(Node* node){
        if(node==nullptr)return;

        cout<<node->data<<" ";
        PreOrderTraversalRecursive(node->left);
        PreOrderTraversalRecursive(node->right);
    }
};
int main(){
BinaryTree BT;
BT.insert(12);
BT.insert(35);
BT.insert(2);
BT.insert(45);
BT.insert(10);
cout<<"PreOrder traversal : ";
BT.PreOrderTraversal();
return 0;
}