#include <iostream>
using namespace std;

class Checker {
    char stack[100];
    int top;
    int N;

public:
    Checker() {
        top = -1;
        N = 100;
    }

    int isEmpty() {
        return (top==-1);
    }
    int isFull() {
        return (top==N-1);
    }
    void push(char ch) {
        if (isFull())
            cout << "Stack overflow!!\n";
        else
            stack[++top] = ch;
    }
    char pop() {
        if (isEmpty()) {
            cout << "Stack underflow\n";
            return '\0';
        } else {
            return stack[top--];
        }
    }
    char peek() {
        if (isEmpty())
            return '\0';
        else
            return stack[top];
    }
    int isBalanced(const string& exp) {
        for (char ch : exp) {
            if (ch == '(' || ch == '{' || ch == '[') {
                push(ch);
            } else if (ch == ')' || ch == '}' || ch == ']') {
                if (isEmpty())
                    return 0;
                char t = peek();
                if ((ch == ')' && t == '(') ||
                    (ch == '}' && t == '{') ||
                    (ch == ']' && t == '[')) {
                    pop();
                } else {
                    return 0;
                }
            }
        }
        return isEmpty();
    }
};
int main() {
    Checker c;
    string expression;

    cout << "Enter expression: ";
    cin >> expression;

    if (c.isBalanced(expression))
        cout << "Expression is Balanced" << endl;
    else
        cout << "Expression is NOT Balanced" << endl;

    return 0;
}
