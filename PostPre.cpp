#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

bool isValidPrefixExpression(string prefix) {
    stack<int> st;
    for (int i = prefix.size() - 1; i >= 0; i--) {
        char c = prefix[i];
        if (isdigit(c)) {
            st.push(c - '0');
        } else if (c != ' ') {
            if (st.size() < 2) return false;
            int op1 = st.top(); st.pop();
            int op2 = st.top(); st.pop();
            if (c == '+' || c == '-' || c == '*' || (c == '/' && op1 != 0)) {
                st.push(c == '+' ? op1 + op2 : (c == '-' ? op1 - op2 : (c == '*' ? op1 * op2 : op2 / op1)));
            } else {
                return false;
            }
        }
    }
    return st.size() == 1;
}

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
int main() {
    string prefixExpression = "+ 3 * 2 5";
    cout << (isValidPrefixExpression(prefixExpression) ? "Valid prefix" : "Invalid prefix") <<endl;
    string postfixExpression = "42 4 * 2 +";
    cout << (isValidPostfixExpression(postfixExpression) ? "Valid postfix" : "Invalid postfix") <<endl;
    return 0;
}
