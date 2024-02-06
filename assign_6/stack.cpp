#include<iostream>
#include<vector>

class Stack {
private:
    int capacity;
    std::vector<int> stack;

public:
    Stack(int capacity) : capacity(capacity) {}

    bool is_empty() {
        return stack.empty();
    }

    bool is_full() {
        return stack.size() == capacity;
    }

    void push(int data) {
        if (is_full()) {
            std::cout << "Stack overflow. Cannot push element." << std::endl;
        } else {
            stack.push_back(data);
            std::cout << "Pushed " << data << " onto the stack." << std::endl;
        }
    }

    int pop() {
        if (is_empty()) {
            std::cout << "Stack underflow. Cannot pop element." << std::endl;
            return -1;
        } else {
            int data = stack.back();
            stack.pop_back();
            std::cout << "Popped " << data << " from the stack." << std::endl;
            return data;
        }
    }

    void display() {
        if (is_empty()) {
            std::cout << "Stack is empty." << std::endl;
        } else {
            std::cout << "Stack elements:" << std::endl;
            for (int i = stack.size() - 1; i >= 0; --i) {
                std::cout << stack[i] << std::endl;
            }
        }
    }

    void clear() {
        stack.clear();
        std::cout << "Stack cleared." << std::endl;
    }
};

int main() {
    int stack_capacity;
    std::cout << "Enter the capacity of the stack: ";
    std::cin >> stack_capacity;

    Stack my_stack(stack_capacity);

    int choice;
    do {
        std::cout << "\nMenu:\n";
        std::cout << "1. Push\n";
        std::cout << "2. Pop\n";
        std::cout << "3. Display\n";
        std::cout << "4. Clear Stack\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                int data;
                std::cout << "Enter the element to push: ";
                std::cin >> data;
                my_stack.push(data);
                break;

            case 2:
                my_stack.pop();
                break;

            case 3:
                my_stack.display();
                break;

            case 4:
                my_stack.clear();
                break;

            case 0:
                std::cout << "Exiting program.\n";
                break;

            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}
