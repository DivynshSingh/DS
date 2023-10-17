#include <iostream>
#include <stack>
using namespace std;
class MinStack {
private:
    stack<int> mainStack;
    stack<int> minStack;
public:
    MinStack() {}

    void push(int x) {
        if (mainStack.empty()) {
            mainStack.push(x);
            minStack.push(x);
        } else {
            mainStack.push(x);
            int currentMin = minStack.top();
            if (x < currentMin) {
                minStack.push(x);
            } else {
                minStack.push(currentMin);
            }
        }
    }

    void pop() {
        if (!mainStack.empty()) {
            mainStack.pop();
            minStack.pop();
        }
    }

    int top() {
        return mainStack.top();
    }

    int getMin() {
        return minStack.top();
    }
};

int main() {
    MinStack stack;

    stack.push(3);
    stack.push(5);
    stack.push(2);
    stack.push(1);

    cout << "Minimum element: " << stack.getMin() << endl;
    return 0;
}
