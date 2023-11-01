#include <iostream>
using namespace std;

struct avlnode {
    int data;
    avlnode* left;
    avlnode* right;
    int height;

    avlnode(int value) : data(value), left(nullptr), right(nullptr), height(1) {}
};

int getheight(avlnode* node) {
    return (node != nullptr) ? node->height : 0;
}

void updateheight(avlnode* node) {
    node->height = 1 + max(getheight(node->left), getheight(node->right));
}

avlnode* rotateright(avlnode* y) {
    avlnode* x = y->left;
    avlnode* t2 = x->right;

    x->right = y;
    y->left = t2;

    updateheight(y);
    updateheight(x);

    return x;
}

avlnode* rotateleft(avlnode* x) {
    avlnode* y = x->right;
    avlnode* t2 = y->left;

    y->left = x;
    x->right = t2;

    updateheight(x);
    updateheight(y);

    return y;
}

avlnode* balance(avlnode* node) {
    if (node == nullptr) return node;

    updateheight(node);

    int bf = getheight(node->left) - getheight(node->right);

    if (bf > 1 && node->data > node->left->data)
        return rotateright(node);

    if (bf < -1 && node->data < node->right->data)
        return rotateleft(node);

    if (bf > 1 && node->data < node->left->data) {
        node->left = rotateleft(node->left);
        return rotateright(node);
    }

    if (bf < -1 && node->data > node->right->data) {
        node->right = rotateright(node->right);
        return rotateleft(node);
    }

    return node;
}

avlnode* insert(avlnode* node, int value) {
    if (node == nullptr)
        return new avlnode(value);

    if (value < node->data)
        node->left = insert(node->left, value);
    else if (value > node->data)
        node->right = insert(node->right, value);
    else
        return node;

    return balance(node);
}

void inordertraversal(avlnode* root) {
    if (root) {
        inordertraversal(root->left);
        cout << root->data << " ";
        inordertraversal(root->right);
    }
}

int main() {
    avlnode* root = nullptr;

    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    cout << "inorder traversal of the avl tree: ";
    inordertraversal(root);
    cout << endl;

    return 0;
}
