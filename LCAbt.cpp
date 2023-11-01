#include <iostream>
using namespace std;

struct node{
    int val;
    node* left;
    node* right;
    node(int value) : val(value), left(nullptr), right(nullptr) {}
};

node* LCA(node* root, node* p, node* q) {
    if (root == nullptr) {
        return nullptr;
    }

    if (root == p || root == q) {
        return root;
    }

    node* left = LCA(root->left, p, q);
    node* right = LCA(root->right, p, q);

    if (left && right) {
        return root;
    }

    return left ? left : right;
}

int main() {
    node* root = new node(3);
    root->left = new node(5);
    root->right = new node(1);
    root->left->left = new node(6);
    root->left->right = new node(2);
    root->right->left = new node(0);
    root->right->right = new node(8);
    root->left->right->left = new node(7);
    root->left->right->right = new node(4);

    node* p = root->left->left;
    node* q = root->left->right;
    
    node* lca = LCA(root, p, q);

    if (lca) {
        cout << "lowest common ancestor of " << p->val << " and " << q->val << " is: " << lca->val << endl;
    } else {
        cout << "lowest common ancestor not found" << endl;
    }
    return 0;
}
