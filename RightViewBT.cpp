#include <iostream>
#include <queue>
using namespace std;

struct node {
    int val;
    node* left;
    node* right;
    node(int value) : val(value), left(nullptr), right(nullptr) {}
};

void rightView(node* root) {
if(root==nullptr){
    return;
}
queue<node*> q;
q.push(root);
while (!q.empty()) {
    int levelSize = q.size();
    for (int i = 0; i < levelSize; i++) {
        node* current = q.front();
        q.pop();
        if (i == levelSize - 1) {
            cout << current->val << " ";
        }
        if (current->left) {
            q.push(current->left);
        }
        if (current->right) {
            q.push(current->right);
        }
    }
}
}
int main(){
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    // root->right->right->left = new node(8);
    root->left->right->left = new node(9);

    cout << "binary tree as seen from the right is: ";
    rightView(root);

    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right->left;
    delete root->right->right;
    delete root->right;
    delete root;
    return 0;
}
