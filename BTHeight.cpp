#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};
int findHeight(Node* root) {
    if (root == nullptr) {
        return 0;
    } else {
        int leftHeight = findHeight(root->left);
        int rightHeight = findHeight(root->right);
        return 1 + max(leftHeight, rightHeight);
    }
}

int main() {
Node* root = new Node(1);
root->left = new Node(2);
root->right = new Node(3);
root->left->left = new Node(4);
root->left->right = new Node(5);
root->right->left = new Node(6);
root->right->right = new Node(7);
int height = findHeight(root);
cout << "height of tree is: " << height << endl;
return 0;
}