#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <stdexcept>

template<typename T>
class Stack {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& data) : data(data), next(nullptr) {}
    };

    Node* top;

public:
    Stack() : top(nullptr) {}

    ~Stack() {
        clear();
    }

    void push(const T& data) {
        Node* newNode = new Node(data);
        newNode->next = top;
        top = newNode;
    }

    T pop() {
        if (isEmpty()) {
            throw std::out_of_range("Stack is empty.");
        }
        T data = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return data;
    }

    T& peek() const {
        if (isEmpty()) {
            throw std::out_of_range("Stack is empty.");
        }
        return top->data;
    }

    bool isEmpty() const {
        return top == nullptr;
    }

    void clear() {
        while (!isEmpty()) {
            pop();
        }
    }
};

#endif 
