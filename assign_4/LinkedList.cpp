#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    void display() {
        Node* current = head;
        while (current) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "nullptr" << endl;
    }

    void insertBeg(int data) {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }

    void deleteNode(int key) {
        Node* current = head;
        Node* prev = nullptr;

        // If the key is found at the head
        if (current && current->data == key) {
            head = current->next;
            delete current;
            return;
        }

        while (current && current->data != key) {
            prev = current;
            current = current->next;
        }

        if (!current) {
            cout << key << " not found in the list." << endl;
            return;
        }

        prev->next = current->next;
        delete current;
    }

    void concatenate(LinkedList& otherList) {
        if (!head) {
            head = otherList.head;
        } else {
            Node* current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = otherList.head;
        }
        // Avoiding memory leaks in the other list
        otherList.head = nullptr;
    }

    void search(int key) {
        Node* current = head;
        int index = 0;
        while (current) {
            if (current->data == key) {
                cout << key << " found at index " << index << "." << endl;
                return;
            }
            current = current->next;
            index++;
        }

        cout << key << " not found in the list." << std::endl;
    }

    ~LinkedList() {
        
        Node* current = head;
        Node* nextNode;

        while (current) {
            nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }
};

int main() {
    LinkedList list;

    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Insert at the beginning\n";
        cout << "2. Delete by key\n";
        cout << "3. Display\n";
        cout << "4. Concatenate\n";
        cout << "5. Search\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int data;
                cout << "Enter data to insert: ";
                cin >> data;
                list.insertBeg(data);
                break;
            }
            case 2: {
                int key;
                cout << "Enter key to delete: ";
                cin >> key;
                list.deleteNode(key);
                break;
            }
            case 3:
                cout << "Linked List: ";
                list.display();
                break;
            case 4: {
                LinkedList list2;
                int data;
                cout << "Enter data for the second list (enter -1 to stop): ";
                while (true) {
                    cin >> data;
                    if (data == -1) {
                        break;
                    }
                    list2.insertBeg(data);
                }
                list.concatenate(list2);
                break;
            }
            case 5: {
                int key;
                cout << "Enter key to search: ";
                cin >> key;
                list.search(key);
                break;
            }
        }
    } while (choice != 0);

    return 0;
}
