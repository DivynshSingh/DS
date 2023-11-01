#include <iostream>
#include <map>
#include <queue>
using namespace std;

struct node{
    int val;
    node* left;
    node* right;
    node(int value) : val(value), left(nullptr), right(nullptr) {}
};

void topView(node* root) {
    if (root == nullptr) {
        return;
    }
    map<int, int> topViewMap;
    queue<pair<node*, int>> q;

    q.push({root, 0});

    while (!q.empty()) {
        node* current = q.front().first;
        int hd = q.front().second;
        q.pop();

        if (topViewMap.find(hd) == topViewMap.end()) {
            topViewMap[hd] = current->val;
        }

        if (current->left) {
            q.push({current->left, hd - 1});
        }

        if (current->right) {
            q.push({current->right, hd + 1});
        }
    }

    for (const auto& entry : topViewMap) {
        cout << entry.second << " ";
    }
    cout << endl;
}

int main() {
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->right = new node(4);
    root->left->right->right = new node(5);
    root->left->right->right->right = new node(6);

    cout << "top-view of the binary tree is: ";
    topView(root);

    delete root->left->right->right->right;
    delete root->left->right->right;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
