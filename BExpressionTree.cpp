#include <iostream>
#include <stack>
using namespace std;

struct Node{
    char data;
    Node* left;
    Node* right;
    Node(char value) : data(value), left(nullptr), right(nullptr) {}
};

bool is_operator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

void inorder_traversal(Node* root) {
    if (root) {
        if (is_operator(root->data)) {
            cout << "(";
        }
        inorder_traversal(root->left);
        cout << root->data;
        inorder_traversal(root->right);
        if (is_operator(root->data)) {
            cout << ")";
        }
    }
}

Node* build_expression_tree(string postfix_expression) {
    stack<Node*> st;
    for (char c : postfix_expression) {
        Node* node = new Node(c);
        if (is_operator(c)) {
            node->right = st.top();
            st.pop();
            node->left = st.top();
            st.pop();
        }
        st.push(node);
    }
    return st.top();
}

int main() {
    string postfix = "ab+cd-*";
    Node* root = build_expression_tree(postfix);
    cout << "Infix expression obtained from the expression tree: ";
    inorder_traversal(root);
    cout << endl;

    return 0;
}
