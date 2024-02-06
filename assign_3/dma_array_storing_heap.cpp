#include <iostream>


class Heap {
private:
    int *array;
    int capacity;
    int size;


public:
    // Constructor to initialize the heap with a given capacity
    Heap(int capacity) : capacity(capacity), size(0) {
        array = new int[capacity];
    }


    // Destructor to free the dynamically allocated memory
    ~Heap() {
        delete[] array;
    }


    // Function to insert a value into the heap
    void insert(int value) {
        if (size == capacity) {
            std::cout << "Heap is full. Cannot insert more elements." << std::endl;
            return;
        }


        // Insert the element at the end
        array[size] = value;


        // Perform heapify-up to maintain the heap property
        heapifyUp(size);


        // Increment the size
        size++;
    }


    // Function to delete the root element from the heap
    void deleteRoot() {
        if (size == 0) {
            std::cout << "Heap is empty. Cannot delete root." << std::endl;
            return;
        }


        // Swap the root with the last element
        std::swap(array[0], array[size - 1]);


        // Perform heapify-down to maintain the heap property
        heapifyDown(0);


        // Decrement the size
        size--;
    }


    // Function to display the elements of the heap
    void display() const {
        std::cout << "Heap elements: ";
        for (int i = 0; i < size; i++) {
            std::cout << array[i] << " ";
        }
        std::cout << std::endl;
    }


private:
    // Helper function to perform heapify-up
    void heapifyUp(int index) {
        while (index > 0 && array[parent(index)] < array[index]) {
            std::swap(array[parent(index)], array[index]);
            index = parent(index);
        }
    }


    // Helper function to perform heapify-down
    void heapifyDown(int index) {
        int maxIndex = index;
        int leftChild = left(index);
        int rightChild = right(index);


        if (leftChild < size && array[leftChild] > array[maxIndex]) {
            maxIndex = leftChild;
        }


        if (rightChild < size && array[rightChild] > array[maxIndex]) {
            maxIndex = rightChild;
        }


        if (index != maxIndex) {
            std::swap(array[index], array[maxIndex]);
            heapifyDown(maxIndex);
        }
    }


    // Helper functions to calculate parent and child indices
    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return 2 * i + 1; }
    int right(int i) { return 2 * i + 2; }
};


int main() {
    using namespace std;


    int capacity;
    cout << "Enter the capacity of the heap: ";
    cin >> capacity;


    Heap heap(capacity);


    int choice, value;


    do {
        cout << "\nHeap Operations:\n";
        cout << "1. Insert\n";
        cout << "2. Delete Root\n";
        cout << "3. Display\n";
        cout << "4. Quit\n";


        cout << "Enter your choice: ";
        cin >> choice;


        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                heap.insert(value);
                break;
            case 2:
                heap.deleteRoot();
                break;
            case 3:
                heap.display();
                break;
            case 4:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 4);


    return 0;
}

