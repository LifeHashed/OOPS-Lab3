
#include <iostream>
#include <vector>
#include <stdexcept>

template<typename T>
class MaxHeap {
private:
    std::vector<T> heap;

    
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
    
    MaxHeap() {}

    
    MaxHeap(const std::vector<T>& array) : heap(array) {
        
        int size = heap.size();
        for (int i = (size - 1) / 2; i >= 0; --i) {
            heapifyDown(i);
        }
    }

    T findMax() const {
        if (!heap.empty()) {
            return heap.front();
        } else {
            throw std::out_of_range("Heap is empty.");
        }
    }

    void insert(const T& value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    T extractMax() {
        if (heap.empty()) {
            throw std::out_of_range("Heap is empty.");
        }

        T maxElement = heap.front();
        heap.front() = heap.back();
        heap.pop_back();
        heapifyDown(0);

        return maxElement;
    }

    
    void deleteMax() {
        extractMax(); 
    }

    
    void replace(int index, const T& newValue) {
        if (index >= 0 && index < heap.size()) {
            heap[index] = newValue;

            
            if (index > 0 && heap[index] > heap[(index - 1) / 2]) {
                heapifyUp(index);
            } else {
                heapifyDown(index);
            }
        } else {
            throw std::out_of_range("Invalid index.");
        }
    }

    
    void display() const {
        for (const T& value : heap) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    MaxHeap<char> maxHeap;

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

        try {
            switch (choice) {
                case 1: {
                    char value;
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
                    int index;
                    char newValue;
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
        } catch (const std::out_of_range& e) {
            std::cerr << "Exception: " << e.what() << std::endl;
        }
    } while (choice != 0);

    return 0;
}














































































































































































