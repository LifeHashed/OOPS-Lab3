#include<iostream>
#include<queue>

class Queue {
private:
    int capacity;
    std::queue<int> q;

public:
    Queue(int capacity) : capacity(capacity) {}

    bool is_empty() {
        return q.empty();
    }

    bool is_full() {
        return q.size() == capacity;
    }

    void enqueue(int data) {
        if (is_full()) {
            std::cout << "Queue overflow. Cannot enqueue element." << std::endl;
        } else {
            q.push(data);
            std::cout << "Enqueued " << data << " into the queue." << std::endl;
        }
    }

    int dequeue() {
        if (is_empty()) {
            std::cout << "Queue underflow. Cannot dequeue element." << std::endl;
            return -1;
        } else {
            int data = q.front();
            q.pop();
            std::cout << "Dequeued " << data << " from the queue." << std::endl;
            return data;
        }
    }

    void display() {
        if (is_empty()) {
            std::cout << "Queue is empty." << std::endl;
        } else {
            std::queue<int> tempQ = q;
            std::cout << "Queue elements:" << std::endl;
            while (!tempQ.empty()) {
                std::cout << tempQ.front() << std::endl;
                tempQ.pop();
            }
        }
    }

    void clear() {
        while (!q.empty()) {
            q.pop();
        }
        std::cout << "Queue cleared." << std::endl;
    }
};

int main() {
    int queue_capacity;
    std::cout << "Enter the capacity of the queue: ";
    std::cin >> queue_capacity;

    Queue my_queue(queue_capacity);

    int choice;
    do {
        std::cout << "\nMenu:\n";
        std::cout << "1. Enqueue\n";
        std::cout << "2. Dequeue\n";
        std::cout << "3. Display\n";
        std::cout << "4. Clear Queue\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                int data;
                std::cout << "Enter the element to enqueue: ";
                std::cin >> data;
                my_queue.enqueue(data);
                break;

            case 2:
                my_queue.dequeue();
                break;

            case 3:
                my_queue.display();
                break;

            case 4:
                my_queue.clear();
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
