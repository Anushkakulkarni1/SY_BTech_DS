#include <iostream>
#include <cstring>
#include <string>
#define N 10
using namespace std;

class Stack {
public:
    char arr[N];
    int top;

    Stack() {
        top = -1;
    }

    void push(char c) {
        if (top == N - 1)
            cout << "Stack overflow\n";
        else
            arr[++top] = c;
    }

    char pop() {
        if (top == -1) {
            // cout << "Stack underflow\n";
            return '\0';
        } else {
            return arr[top--];
        }
    }

    char peek() {
        if (top == -1)
            return '\0';
        return arr[top];
    }

    int precedence(char opr) {
        if (opr == '*' || opr == '/')
            return 2;
        if (opr == '+' || opr == '-')
            return 1;
        if (opr == '(')
            return 0;
        return -1;
    }

    char associativity(char opr) {
        if (opr == '*' || opr == '/' || opr == '+' || opr == '-')
            return 'L';
        else
            return 'R';
    }

    string InfixToPostfixConversion(const string& ex);
};

string Stack::InfixToPostfixConversion(const string& ex) {
    string postfix;
    char ch, ch1;

    for (int i = 0; i < ex.length(); i++) {
        ch = ex[i];

        if (isalnum(ch)) {  // Operand
            postfix += ch;
        } 
        else if (ch == '(') {
            push(ch);
        } 
        else if (ch == ')') {
            while (peek() != '(' && top != -1) {
                postfix += pop();
            }
            pop(); // Remove '('
        } 
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            while (top != -1 && precedence(ch) <= precedence(peek())) {
                postfix += pop();
            }
            push(ch);
        }
    }

    // Pop all remaining operators
    while (top != -1) {
        postfix += pop();
    }

    return postfix;
}

int main() {
    Stack s;
    string ex;

    cout << "Enter an expression: ";
    cin >> ex;

    string op_exp = s.InfixToPostfixConversion(ex);
    cout << "\nPostfix Expression is: " << op_exp << endl;

    return 0;
}

