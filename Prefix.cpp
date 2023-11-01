#include <iostream>
#include <stack>
#include <string>
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
return st.size()==1;    
}
int main(){
  string prefixExpression = "+ 3 * 2 5";
  string prefixExpression1 = "- - 3 0 * 8 9";
  string prefixExpression2 = " * + 3 4 5";
  cout << (isValidPrefixExpression(prefixExpression) ? "Valid prefix" : "Invalid prefix") <<endl;
  cout << (isValidPrefixExpression(prefixExpression1) ? "Valid prefix" : "Invalid prefix") <<endl;
  cout << (isValidPrefixExpression(prefixExpression2) ? "Valid prefix" : "Invalid prefix") <<endl;
  return 0;
}