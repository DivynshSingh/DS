#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};
class Stack {
private:
    struct Node* top;
public:
    Stack() : top(nullptr) {}
    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
    }
    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty. Cannot pop." << endl;
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
    }
    bool isEmpty() {
        return top == nullptr;
    }
    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty. Cannot peek." << endl;
            return -1;
        }
        return top->data;
    }
};
int main() {
    Stack stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);

    cout << "Top element of stack: " << stack.peek() << endl;
    stack.pop();
    cout << "Top element after popping: " << stack.peek() << endl;

return 0;
}