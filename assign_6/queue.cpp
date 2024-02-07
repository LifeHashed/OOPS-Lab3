#include <iostream>
using namespace std;

class Queue {
private:
    int front, rear, size;
    int *array;

public:
    Queue(int maxSize) : front(-1), rear(-1), size(maxSize) {
        array = new int[size];
    }

    ~Queue() {
        delete[] array;
    }

    void enqueue(int value) {
        if ((rear + 1) % size != front) {
            if (isEmpty()) {
                front = rear = 0;
            } else {
                rear = (rear + 1) % size;
            }
            array[rear] = value;
            cout << "Enqueued: " << value << endl;
        } else {
            cout << "Queue is full! Cannot enqueue more elements." << endl;
        }
    }

    void dequeue() {
        if (!isEmpty()) {
            int removedValue = array[front];
            if (front == rear) {
                front = rear = -1;
            } else {
                front = (front + 1) % size;
            }
            cout << "Dequeued: " << removedValue << endl;
        } else {
            cout << "Queue is empty! Cannot dequeue from an empty queue." << endl;
        }
    }

    bool isEmpty() {
        return front == -1 && rear == -1;
    }

    bool isFull() {
        return (rear + 1) % size == front;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
        } else {
            cout << "Queue elements: ";
            int i = front;
            do {
                cout << array[i] << " ";
                i = (i + 1) % size;
            } while (i != (rear + 1) % size);
            cout << endl;
        }
    }
};

int main() {
    int maxSize;
    cout << "Enter the maximum size of the queue: ";
    cin >> maxSize;

    Queue queue(maxSize);

    int n, el;
    cout << "Enter Number of elements:" << endl;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Enter element to be enqueued:" << endl;
        cin >> el;
        queue.enqueue(el);
    }

    queue.display();
    queue.dequeue();
    queue.display();
    cout << "Is queue empty? " << (queue.isEmpty() ? "Yes" : "No") << endl;
    cout << "Is queue full? " << (queue.isFull() ? "Yes" : "No") << endl;

    return 0;
}
