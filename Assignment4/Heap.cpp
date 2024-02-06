#include <iostream>
#include <vector>

class MaxHeap {
private:
    std::vector<int> heap;

    // Helper function to maintain the heap property after insertion
    void heapifyUp(int index) {
        while (index > 0) {
            int parentIndex = (index - 1) / 2;
            if (heap[index] > heap[parentIndex]) {
                std::swap(heap[index], heap[parentIndex]);
                index = parentIndex;
            } else {
                break;
            }
        }
    }

    // Helper function to maintain the heap property after extraction or deletion
    void heapifyDown(int index) {
        int size = heap.size();
        while (index < size) {
            int leftChild = 2 * index + 1;
            int rightChild = 2 * index + 2;
            int largest = index;

            if (leftChild < size && heap[leftChild] > heap[largest]) {
                largest = leftChild;
            }

            if (rightChild < size && heap[rightChild] > heap[largest]) {
                largest = rightChild;
            }

            if (largest != index) {
                std::swap(heap[index], heap[largest]);
                index = largest;
            } else {
                break;
            }
        }
    }

public:
    // Initialize an empty heap
    MaxHeap() {}

    // Construct a heap from a given array
    MaxHeap(const std::vector<int>& array) : heap(array) {
        // Build heap bottom-up starting from the last non-leaf node
        int size = heap.size();
        for (int i = (size - 1) / 2; i >= 0; --i) {
            heapifyDown(i);
        }
    }

    // Find the maximum element
    int findMax() const {
        if (!heap.empty()) {
            return heap.front();
        } else {
            std::cerr << "Heap is empty." << std::endl;
            return -1; // Assuming -1 as an indicator for an empty heap
        }
    }

    // Insert an element into the heap
    void insert(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    // Extract the maximum element
    int extractMax() {
        if (heap.empty()) {
            std::cerr << "Heap is empty." << std::endl;
            return -1; // Assuming -1 as an indicator for an empty heap
        }

        int maxElement = heap.front();
        heap.front() = heap.back();
        heap.pop_back();
        heapifyDown(0);

        return maxElement;
    }

    // Delete the maximum element
    void deleteMax() {
        extractMax(); // Deleting the maximum element is equivalent to extracting it
    }

    // Replace an element at a given index with a new value
    void replace(int index, int newValue) {
        if (index >= 0 && index < heap.size()) {
            heap[index] = newValue;

            // Check if the value is greater than its parent, then fix the heap
            if (index > 0 && heap[index] > heap[(index - 1) / 2]) {
                heapifyUp(index);
            } else {
                heapifyDown(index);
            }
        } else {
            std::cerr << "Invalid index." << std::endl;
        }
    }

    // Display the elements of the heap
    void display() const {
        for (int value : heap) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    MaxHeap maxHeap;

    int choice;
    do {
        std::cout << "\nMenu:\n";
        std::cout << "1. Insert element\n";
        std::cout << "2. Find Max element\n";
        std::cout << "3. Extract Max element\n";
        std::cout << "4. Delete Max element\n";
        std::cout << "5. Replace element at index\n";
        std::cout << "6. Display heap\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                int value;
                std::cout << "Enter value to insert: ";
                std::cin >> value;
                maxHeap.insert(value);
                break;
            }
            case 2:
                std::cout << "Max Element: " << maxHeap.findMax() << std::endl;
                break;
            case 3:
                std::cout << "Extracted Max Element: " << maxHeap.extractMax() << std::endl;
                break;
            case 4:
                maxHeap.deleteMax();
                std::cout << "Max Element deleted.\n";
                break;
            case 5: {
                int index, newValue;
                std::cout << "Enter index to replace: ";
                std::cin >> index;
                std::cout << "Enter new value: ";
                std::cin >> newValue;
                maxHeap.replace(index, newValue);
                break;
            }
            case 6:
                std::cout << "Current Max Heap: ";
                maxHeap.display();
                break;
        }
    } while (choice != 0);

    return 0;
}
