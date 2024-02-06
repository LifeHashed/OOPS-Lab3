#include <iostream>
using namespace std;

class Queue{
    private:
    static const int MAX_SIZE=100;
    int front;
    int rear;
    int arr[MAX_SIZE];

    public:
      Queue() : front(-1), rear(-1) {}

     void enqueue(int value) {
        if (rear < MAX_SIZE - 1) {
            if (front == -1) {
                front = 0;
            }
            arr[++rear] = value;
            cout << "Enqueued: " << value << endl;
        } else {
            cout << "Queue overflow! Cannot enqueue more elements." << endl;
        }
    }

     void dequeue() {
        if (front <= rear && front != -1) {
            cout << "Dequeued: " << arr[front++] << endl;
            if (front > rear) {
                front = rear = -1; // Reset queue when empty
            }
        } else {
            cout << "Queue underflow! Cannot dequeue from an empty queue." << endl;
        }
    }

     void initialize() {
        front = rear = -1;
    }

    bool isEmpty() const {
        return front == -1;
    }

    bool isFull() const {
        return rear == MAX_SIZE - 1;
    }

    void display(){
        if(isEmpty()){
            cout<<"Queue is empty"<<endl;
        }
        else{
            cout<<"Queue Elements:";
            for(int i=front;i<=rear;i++){
                cout<<arr[i]<<" "<<endl;
            }
            cout<<endl;
        }

    }

};

int main(){
    Queue queue;
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.display();

    queue.dequeue();
    queue.dequeue();
    queue.display();

    cout << "Is queue empty? " << (queue.isEmpty() ? "Yes" : "No") << endl;
    cout << "Is queue full? " << (queue.isFull() ? "Yes" : "No") << endl;

    return 0;

}
