#include <iostream>
#include <string>
using namespace std;

class Stack {
    char arr[100];
    int top = -1;

public:
    void push(char c) {
        if (top == 99)
            cout << "Stack Overflow\n";
        else
            arr[++top] = c;
    }

    char pop() {
        if (isEmpty()) {
            cout << "Stack Underflow\n";
            return '\0';
        } else {
            return arr[top--];
        }
    }

    char peek() {
        if (isEmpty())
            return '\0';
        return arr[top];
    }

    bool isEmpty() {
        return top == -1;
    }
};

bool isBalanced(string expr) {
    Stack s;
    for (char ch : expr) {
        if (ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);
        } 
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (s.isEmpty())
                return false;
            char top = s.pop();
            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '[')) {
                return false;
            }
        }
    }
    return s.isEmpty();
}

int main() {
    string expression;
    cout << "Enter an expression: ";
    cin >> expression;

    if (isBalanced(expression))
        cout << "Balanced expression" << endl;
    else
        cout << "Not balanced" << endl;

    return 0;
}
