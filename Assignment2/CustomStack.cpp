#include <iostream>
using namespace std;

class Stack{
    private:
    static const int MAX_SIZE=100;
    int top;
    int arr[MAX_SIZE];


    public:
    Stack() : top(-1) {}

    void push(int value) {
        if (top < MAX_SIZE - 1) {
            arr[++top] = value;
            cout << "Pushed: " << value << endl;
        } else {
            cout << "Stack overflow! Cannot push more elements." << endl;
        }
    }

    void pop() {
        if (top >= 0) {
            cout << "Popped: " << arr[top--] <<endl;
        } else {
            cout << "Stack underflow! Cannot pop from an empty stack." << endl;
        }
    }

    void initialize() {
    top = -1; }

    bool isEmpty() const {
        return top == -1;
    }

    bool isFull() const {
        return top == MAX_SIZE - 1;
    }

        void display() const {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
        } else {
            cout << "Stack elements: ";
            for (int i = 0; i <= top; ++i) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Stack stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.display();

    stack.pop();
    stack.display();

cout << "Is stack empty? " << (stack.isEmpty() ? "Yes" : "No") << endl;
cout << "Is stack full? " << (stack.isFull() ? "Yes" : "No") << endl;

    return 0;
}












