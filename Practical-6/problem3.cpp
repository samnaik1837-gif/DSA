#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Check operator priority
int priority(char op) {
    if (op == '+' || op == '-')
        return 1;

    if (op == '*' || op == '/')
        return 2;

    if (op == '^')
        return 3;

    return 0;
}

// Convert infix to postfix
string infixToPostfix(string infix) {
    stack<char> s;
    string postfix = "";

    for (char ch : infix) {

        // If character is an operand
        if (isalnum(ch)) {
            postfix += ch;
        }

        // Opening bracket
        else if (ch == '(') {
            s.push(ch);
        }

        // Closing bracket
        else if (ch == ')') {

            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }

            // Remove opening bracket
            if (!s.empty())
                s.pop();
        }

        // If character is an operator
        else {
            while (!s.empty() &&
                   priority(s.top()) >= priority(ch)) {
                postfix += s.top();
                s.pop();
            }

            s.push(ch);
        }
    }

    // Pop remaining operators
    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }

    return postfix;
}

int main() {
    string infix;

    cout << "Enter infix expression: ";
    cin >> infix;

    cout << "Postfix expression: "
         << infixToPostfix(infix);

    return 0;
}