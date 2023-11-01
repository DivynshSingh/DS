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

    void inOrderTraversal(){
        inOrderTraversalRecursive(root);
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

    void inOrderTraversalRecursive(Node* node) {
        if (node != nullptr) {
            inOrderTraversalRecursive(node->left);
            cout << node->data << " ";
            inOrderTraversalRecursive(node->right);
        }
    }
};

int main() {
    BinaryTree tree;

    tree.insert(1);
    tree.insert(32);
    tree.insert(7324);
    tree.insert(24);
    tree.insert(234);

    cout << "In-order traversal: ";
    tree.inOrderTraversal();
    cout << endl;

    return 0;
}