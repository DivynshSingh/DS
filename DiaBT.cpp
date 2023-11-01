#include <iostream>
using namespace std;

struct node{
    int data;
    node* left;
    node* right;
    node(int val) : data(val), left(nullptr), right(nullptr) {}
};

int height(node* root) {
    if (root == nullptr)
        return 0;
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return 1 + max(leftHeight, rightHeight);
}

int diameter(node* root) {
    if (root == nullptr)
        return 0;

    int leftDiameter = diameter(root->left);
    int rightDiameter = diameter(root->right);
    
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    
    int currentDiameter = leftHeight + rightHeight + 1;

    return max(currentDiameter, max(leftDiameter, rightDiameter));
}

int main() {
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);

    int d=diameter(root);
    cout<<"diameter of the binary tree is: " <<d<< endl;
    return 0;
}
