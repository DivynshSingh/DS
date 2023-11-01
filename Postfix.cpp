#include<iostream>
#include<string>
#include<stack>
using namespace std;
bool isValidPostfixExpression(string& postfix) {
    stack<int> st;
    string num;

    for (char c : postfix) {
        if (isdigit(c)) {
            num += c;
        } else if (c == ' ') {
            if (!num.empty()) {
                st.push(stoi(num));
                num.clear();
            }
        } else if (c == '+' || c == '-' || c == '*' || c == '/') {
            if (st.size() < 2) return false;
            int op2 = st.top(); st.pop();
            int op1 = st.top(); st.pop();
            if (c == '+') st.push(op1 + op2);
            else if (c == '-') st.push(op1 - op2);
            else if (c == '*') st.push(op1 * op2);
            else if (c == '/') {
                if (op2 == 0) return false;
                st.push(op1 / op2);
            }
        } else {
            return false;
        }
    }

    if (!num.empty()) st.push(stoi(num));

    return st.size() == 1;
}
int main() { // (79*3 +8 )*7*9
    string postfixExpression = "42 4 * 2 +";
    string postfixExpression1 = "51 3 * 2 75 - +";
    string postfixExpression2= "7 9* 79 3 *8 * + *";
    cout << (isValidPostfixExpression(postfixExpression) ? "Valid postfix" : "Invalid postfix") <<endl;
    cout << (isValidPostfixExpression(postfixExpression1) ? "Valid postfix" : "Invalid postfix") <<endl;
    cout << (isValidPostfixExpression(postfixExpression2) ? "Valid postfix" : "Invalid postfix") <<endl;
    return 0;
}
