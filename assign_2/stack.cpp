#include <iostream>
using namespace std;
#define MAX_SIZE 100

class Stack {
private:
    int top;
    int array[MAX_SIZE];

public:
    Stack() : top(-1) {}
    void push(int value) {
        if (top < MAX_SIZE - 1) {
            array[++top] = value;
            cout << "Pushed: " << value << endl;
        } else {
            cout << "Stack overflow! Cannot push more elements." << endl;
        }
    }

    void pop() {
        if (top >= 0) {
            cout << "Popped: " << array[top--] << endl;
        } else {
            cout << "Stack underflow! Cannot pop from an empty stack." << endl;
        }
    }

    void initialize() {
        top = -1;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == MAX_SIZE - 1;
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
        } else {
            cout << "Stack elements: ";
            for (int i = 0; i <= top; ++i) {
                cout << array[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Stack stack;
    int n, el;
    cout << "Enter Number of elements:" << endl;
    cin >> n;
    for (int i=0; i<n; i++){
        cout << "Enter element to be pushed:" << endl;
        cin >> el;
        stack.push(el);
    }
    stack.display();
    stack.pop();
    stack.display();
    cout << "Is stack empty? " << (stack.isEmpty() ? "Yes" : "No") << endl;
    cout << "Is stack full? " << (stack.isFull() ? "Yes" : "No") << endl;
}