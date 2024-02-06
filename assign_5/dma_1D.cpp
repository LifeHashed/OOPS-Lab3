#include <iostream>
using namespace std;

class Heap {
private:
    int* array;
    int size;
    int capacity;

public:
    Heap(int capacity) {
        this->capacity = capacity;
        this->array = new int[capacity];
        this->size = 0;
    }

    ~Heap() {
        delete[] array;
    }

    void insert(int value) {
        if (size < capacity) {
            array[size++] = value;
            heapifyUp(size - 1);
            cout << "Inserted " << value << " into the heap." << endl;
        } else {
            cout << "Heap is full. Cannot insert " << value << "." << endl;
        }
    }

    void remove() {
        if (size > 0) {
            cout << "Removed " << array[0] << " from the heap." << endl;
            array[0] = array[--size];
            heapifyDown(0);
        } else {
            cout << "Heap is empty. Cannot remove." << endl;
        }
    }

    void display() {
        cout << "Heap elements: ";
        for (int i = 0; i < size; ++i) {
            cout << array[i] << " ";
        }
        cout << endl;
    }

private:
    void heapifyUp(int index) {
        int parent = (index - 1) / 2;
        while (index > 0 && array[index] > array[parent]) {
            swap(array[index], array[parent]);
            index = parent;
            parent = (index - 1) / 2;
        }
    }

    void heapifyDown(int index) {
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        int largest = index;
        if (leftChild < size && array[leftChild] > array[largest]) {
            largest = leftChild;
        }
        if (rightChild < size && array[rightChild] > array[largest]) {
            largest = rightChild;
        }
        if (largest != index) {
            swap(array[index], array[largest]);
            heapifyDown(largest);
        }
    }
};


int main() {
    int capacity;
    cout << "Enter the capacity of the heap: ";
    cin >> capacity;
    Heap myHeap(capacity);
    int choice;
    do {
        cout << "\nHeap Operations:\n"
                  << "1. Insert\n"
                  << "2. Remove\n"
                  << "3. Display\n"
                  << "4. Quit\n"
                  << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                int value;
                cout << "Enter the value to insert: ";
                cin >> value;
                myHeap.insert(value);
                break;
            }
            case 2:
                myHeap.remove();
                break;
            case 3:
                myHeap.display();
                break;
            case 4:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);
}
