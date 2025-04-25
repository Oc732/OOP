practical n0.13-/*
Implement C++ program for expression conversion as infix to postfix and its
evaluation using stack based on given conditions:
1. Operands and operator, both must be single character.
2. Input Postfix expression must be in a desired format.
Only '+', '-', '*' and '/ ' operators are expected.
*/


#include <iostream>
#include <algorithm>
#include <cstring> // For handling C-style strings
using namespace std;

class Stack {
private:
    int size;
    int top;
    char* arr;

public:
    Stack(int s) {
        size = s;
        arr = new char[size];
        top = -1;
    }

    ~Stack() {
        delete[] arr;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == size - 1;
    }

    void push(char e) {
        if (!isFull()) {
            arr[++top] = e;
        }
    }

    char pop() {
        if (!isEmpty()) {
            return arr[top--];
        }
        return '\0'; // Return null character if stack is empty
    }

    char peek() {
        if (!isEmpty()) {
            return arr[top];
        }
        return '\0';
    }
};

bool isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

int getPriority(char ch) {
    switch (ch) {
        case '^':
            return 3;
        case '*':
        case '/':
            return 2;
        case '+':
        case '-':
            return 1;
        default:
            return -1;
    }
}

int main() {
    string infix;
    cout << "Enter an Infix expression: ";
    getline(cin, infix);

    // Remove all spaces from the input string
    infix.erase(remove(infix.begin(), infix.end(), ' '), infix.end());

    Stack stack(50);
    string postfix;

    for (char ch : infix) {
        if (ch == '(') {
            stack.push(ch);
        } else if (ch == ')') {
            while (!stack.isEmpty() && stack.peek() != '(') {
                postfix += stack.pop();
                postfix += ' ';
            }
            stack.pop(); // Pop '('
        } else if (isOperator(ch)) {
            while (!stack.isEmpty() && stack.peek() != '(' && getPriority(stack.peek()) >= getPriority(ch)) {
                postfix += stack.pop();
                postfix += ' ';
            }
            stack.push(ch);
        } else { // Operand
            postfix += ch;
            postfix += ' ';
        }
    }

    // Empty the stack after processing the infix expression
    while (!stack.isEmpty()) {
        postfix += stack.pop();
        postfix += ' ';
    }

    cout << "Postfix: " << postfix << endl;
    return 0;
}
