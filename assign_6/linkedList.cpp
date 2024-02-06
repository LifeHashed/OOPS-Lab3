#include<iostream>
#include<cstdlib> // For rand() function

class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

    void clear() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

public:
    LinkedList() : head(nullptr) {}

    ~LinkedList() {
        clear();
    }

    void insert_beg(int data) {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
        std::cout << "Inserted " << data << " at the beginning of the list." << std::endl;
    }

    void display() {
        Node* current = head;
        std::cout << "Linked List: ";
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    void remove(int key) {
        Node* current = head;
        Node* prev = nullptr;

        while (current != nullptr && current->data != key) {
            prev = current;
            current = current->next;
        }

        if (current == nullptr) {
            std::cout << "Key not found in the list." << std::endl;
        } else {
            if (prev == nullptr) {
                // Removing the first node
                head = current->next;
            } else {
                // Removing a node other than the first one
                prev->next = current->next;
            }

            std::cout << "Removed node with key " << key << " from the list." << std::endl;
            delete current;
        }
    }

    void concatenate(LinkedList& other) {
        if (head == nullptr) {
            // If the current list is empty, set it to the other list
            head = other.head;
        } else {
            // Find the end of the current list
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }

            // Concatenate the other list to the end of the current list
            current->next = other.head;
        }

        // Clear the other list after concatenation
        other.head = nullptr;
        std::cout << "Lists concatenated." << std::endl;
    }

    bool search(int key) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == key) {
                return true;
            }
            current = current->next;
        }
        return false;
    }
};

int main() {
    LinkedList list1;
    LinkedList list2;

    // Insert random values into list1
    for (int i = 0; i < 5; ++i) {
        int value = rand() % 100;
        list1.insert_beg(value);
    }

    std::cout << "List 1:" << std::endl;
    list1.display();

    // Insert random values into list2
    for (int i = 0; i < 3; ++i) {
        int value = rand() % 100;
        list2.insert_beg(value);
    }

    std::cout << "List 2:" << std::endl;
    list2.display();

    // Concatenate list2 to list1
    list1.concatenate(list2);

    std::cout << "After concatenation:" << std::endl;
    list1.display();
    list2.display(); // list2 should be empty after concatenation

    // Search for a key in list1
    int searchKey;
    std::cout << "Enter a value to search in the list: ";
    std::cin >> searchKey;
    if (list1.search(searchKey)) {
        std::cout << searchKey << " found in the list." << std::endl;
    } else {
        std::cout << searchKey << " not found in the list." << std::endl;
    }

    // Remove a value from list1
    int removeKey;
    std::cout << "Enter a value to remove from the list: ";
    std::cin >> removeKey;
    list1.remove(removeKey);

    std::cout << "After removal:" << std::endl;
    list1.display();

    return 0;
}
