#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

// Operator precedence
int precedence(char op) {
    if(op == '+' || op == '-') return 1;
    if(op == '*' || op == '/') return 2;
    if(op == '^') return 3;
    return 0;
}

// Step 1: Infix to Postfix
string infixToPostfix(const string &exp) {
    stack<char> st;
    string postfix;

    for(char ch : exp) {
        if(isalnum(ch))
            postfix += ch;
        else if(ch == '(')
            st.push(ch);
        else if(ch == ')') {
            while(!st.empty() && st.top() != '(') {
                postfix += st.top();
                st.pop();
            }
            if(!st.empty()) st.pop(); // pop '('
        }
        else { // operator
            while(!st.empty() && precedence(st.top()) >= precedence(ch)) {
                postfix += st.top();
                st.pop();
            }
            st.push(ch);
        }
    }

    while(!st.empty()) {
        postfix += st.top();
        st.pop();
    }

    return postfix;
}

// Step 2: Postfix to Prefix
string postfixToPrefix(const string &postfix) {
    stack<string> st;

    for(char ch : postfix) {
        if(isalnum(ch))
            st.push(string(1, ch)); // push operand as string
        else {
            string op2 = st.top(); st.pop();
            string op1 = st.top(); st.pop();
            string temp = ch + op1 + op2; // prefix = operator + operand1 + operand2
            st.push(temp);
        }
    }

    return st.top();
}

int main() {
    string infix = "(A+B)*(C-D)";

    cout << "Infix: " << infix << endl;

    string postfix = infixToPostfix(infix);
    cout << "Postfix: " << postfix << endl;

    string prefix = postfixToPrefix(postfix);
    cout << "Prefix: " << prefix << endl;

    return 0;
}
