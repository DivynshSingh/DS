#include <iostream>
#include <map>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};

void bottomView(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    map<int, int> bottomViewMap;
    queue<pair<TreeNode*, int>> q; 

    q.push({root, 0});
    while (!q.empty()) {
        TreeNode* current = q.front().first;
        int hd = q.front().second;
        q.pop();
        bottomViewMap[hd] = current->val;

        if (current->left) {
            q.push({current->left, hd - 1});
        }

        if (current->right) {
            q.push({current->right, hd + 1});
        }
    }

    for (const auto& entry : bottomViewMap) {
        cout << entry.second << " ";
    }
    cout << endl;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->left->right->right = new TreeNode(5);
    root->left->right->right->right = new TreeNode(6);

    cout << "Bottom View of the binary tree: ";
    bottomView(root);

    delete root->left->right->right->right;
    delete root->left->right->right;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
