#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

class Node {
public:
    int key;
    Node* next;

    Node(int k) : key(k), next(nullptr) {}
};

class HashTable {
private:
    std::vector<Node*> table;
    int size;

    
    int hashFunction1(int key) {
        return key % 10;
    }

    
    int hashFunction2(int key) {
        return (key * key) % 10;
    }

public:
    HashTable(int tableSize) : size(tableSize) {
        table.resize(size, nullptr);
    }

    
    bool search(int key, int hashFunction) {
        int hashValue = (hashFunction == 1) ? hashFunction1(key) : hashFunction2(key);

        Node* current = table[hashValue];
        while (current != nullptr) {
            if (current->key == key) {
                return true;
            }
            current = current->next;
        }

        return false; 
    }

    
    void insert(int key, int hashFunction) {
        int hashValue = (hashFunction == 1) ? hashFunction1(key) : hashFunction2(key);

        Node* newNode = new Node(key);
        newNode->next = table[hashValue];
        table[hashValue] = newNode;
    }

  
    void remove(int key, int hashFunction) {
        int hashValue = (hashFunction == 1) ? hashFunction1(key) : hashFunction2(key);

        Node* current = table[hashValue];
        Node* prev = nullptr;

        while (current != nullptr && current->key != key) {
            prev = current;
            current = current->next;
        }

        if (current == nullptr) {
            std::cout << "Key not found. Unable to delete.\n";
            return;
        }

        if (prev == nullptr) {
            table[hashValue] = current->next;
        } else {
            prev->next = current->next;
        }

        delete current;
    }

    // Display the contents of the hash table
    void display() {
        for (int i = 0; i < size; ++i) {
            std::cout << "Bucket " << i << ": ";
            Node* current = table[i];
            while (current != nullptr) {
                std::cout << current->key << " ";
                current = current->next;
            }
            std::cout << std::endl;
        }
    }

    // Calculate the load percentage for each bucket
    void calculateLoad() {
        for (int i = 0; i < size; ++i) {
            int count = 0;
            Node* current = table[i];
            while (current != nullptr) {
                count++;
                current = current->next;
            }

            std::cout << "Bucket " << i << " Load: ";
            if (count > 0) {
                double loadPercentage = static_cast<double>(count) / size * 100;
                std::cout << loadPercentage << "%\n";
            } else {
                std::cout << "0%\n";
            }
        }
    }
};

int main() {
    const int tableSize = 10;
    HashTable hashTable(tableSize);

    
    std::srand(std::time(nullptr));

    
    for (int i = 0; i < 100; ++i) {
        int randomKey = std::rand() % 1000; 
        hashTable.insert(randomKey, 1);
    }

    
    std::cout << "Initial Hash Table:\n";
    hashTable.display();

    
    std::cout << "\nLoad Percentages:\n";
    hashTable.calculateLoad();

    
    int choice, key;
    do {
        std::cout << "\nMenu:\n";
        std::cout << "1. Search\n";
        std::cout << "2. Insert\n";
        std::cout << "3. Delete\n";
        std::cout << "4. Display\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter key to search: ";
                std::cin >> key;
                std::cout << (hashTable.search(key, 1) ? "Key found" : "Key not found") << std::endl;
                break;
            case 2:
                std::cout << "Enter key to insert: ";
                std::cin >> key;
                hashTable.insert(key, 1);
                break;
            case 3:
                std::cout << "Enter key to delete: ";
                std::cin >> key;
                hashTable.remove(key, 1);
                break;
            case 4:
                std::cout << "Current Hash Table:\n";
                hashTable.display();
                break;
        }
    } while (choice != 0);

    return 0;
}
