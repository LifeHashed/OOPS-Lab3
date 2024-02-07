#include <iostream>
using namespace std;
#define MAX_SIZE 100

class Queue {
private:
    int front, rear;
    int array[MAX_SIZE];

public:
    Queue() : front(-1), rear(-1) {}

    void enqueue(int value) {
        if (rear < MAX_SIZE - 1) {
            if (front == -1) {
                front = 0;
            }
            array[++rear] = value;
            cout << "Enqueued: " << value << endl;
        } else {
            cout << "Queue overflow! Cannot enqueue more elements." << endl;
        }
    }

    void dequeue() {
        if (front <= rear && front != -1) {
            cout << "Dequeued: " << array[front++] << endl;
            if (front > rear) {
                front = rear = -1;
            }
        } else {
            cout << "Queue underflow! Cannot dequeue from an empty queue." << endl;
        }
    }

    void initialize() {
        front = rear = -1;
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return rear == MAX_SIZE - 1;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
        } else {
            cout << "Queue elements: ";
            for (int i = front; i <= rear; ++i) {
                cout << array[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Queue queue;
    int n, el;
    cout << "Enter Number of elements:" << endl;
    cin >> n;
    for (int i=0; i<n; i++){
        cout << "Enter element to be enqueued:" << endl;
        cin >> el;
        queue.enqueue(el);
    }
    queue.display();
    queue.dequeue();
    queue.display();
    cout << "Is queue empty? " << (queue.isEmpty() ? "Yes" : "No") << endl;
    cout << "Is queue full? " << (queue.isFull() ? "Yes" : "No") << endl;
}