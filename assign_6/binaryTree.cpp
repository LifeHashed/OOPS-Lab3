#include<iostream>
#include<queue>

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BinaryTree {
private:
    Node* root;

    Node* insert(Node* current, int data) {
        if (current == nullptr) {
            return new Node(data);
        }

        if (data < current->data) {
            current->left = insert(current->left, data);
        } else if (data > current->data) {
            current->right = insert(current->right, data);
        }

        return current;
    }

    Node* find_min(Node* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    Node* remove(Node* current, int data) {
        if (current == nullptr) {
            return current;
        }

        if (data < current->data) {
            current->left = remove(current->left, data);
        } else if (data > current->data) {
            current->right = remove(current->right, data);
        } else {
            // Node to be deleted found

            // Node with only one child or no child
            if (current->left == nullptr) {
                Node* temp = current->right;
                delete current;
                return temp;
            } else if (current->right == nullptr) {
                Node* temp = current->left;
                delete current;
                return temp;
            }

            // Node with two children
            Node* temp = find_min(current->right);
            current->data = temp->data;
            current->right = remove(current->right, temp->data);
        }

        return current;
    }

    bool search(Node* current, int data) {
        if (current == nullptr) {
            return false;
        }

        if (data == current->data) {
            return true;
        } else if (data < current->data) {
            return search(current->left, data);
        } else {
            return search(current->right, data);
        }
    }

    void display_inorder(Node* current) {
        if (current != nullptr) {
            display_inorder(current->left);
            std::cout << current->data << " ";
            display_inorder(current->right);
        }
    }

    int find_height(Node* current) {
        if (current == nullptr) {
            return 0;
        }

        int left_height = find_height(current->left);
        int right_height = find_height(current->right);

        return std::max(left_height, right_height) + 1;
    }

    void display_bfs(Node* current) {
        if (current == nullptr) {
            return;
        }

        std::queue<Node*> q;
        q.push(current);

        while (!q.empty()) {
            Node* node = q.front();
            q.pop();

            std::cout << node->data << " ";

            if (node->left != nullptr) {
                q.push(node->left);
            }

            if (node->right != nullptr) {
                q.push(node->right);
            }
        }
    }

public:
    BinaryTree() : root(nullptr) {}

    void insert(int data) {
        root = insert(root, data);
    }

    void remove(int data) {
        root = remove(root, data);
    }

    bool search(int data) {
        return search(root, data);
    }

    void display_inorder() {
        std::cout << "Inorder Traversal:";
        display_inorder(root);
        std::cout << std::endl;
    }

    int find_height() {
        return find_height(root);
    }

    void display_bfs() {
        std::cout << "BFS Traversal:";
        display_bfs(root);
        std::cout << std::endl;
    }
};

int main() {
    BinaryTree myTree;

    int choice, data;

    do {
        std::cout << "\nMenu:\n";
        std::cout << "1. Insert\n";
        std::cout << "2. Remove\n";
        std::cout << "3. Search\n";
        std::cout << "4. Display Inorder\n";
        std::cout << "5. Find Height\n";
        std::cout << "6. Display BFS\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter the element to insert: ";
                std::cin >> data;
                myTree.insert(data);
                break;

            case 2:
                std::cout << "Enter the element to remove: ";
                std::cin >> data;
                myTree.remove(data);
                break;

            case 3:
                std::cout << "Enter the element to search: ";
                std::cin >> data;
                if (myTree.search(data)) {
                    std::cout << data << " found in the tree." << std::endl;
                } else {
                    std::cout << data << " not found in the tree." << std::endl;
                }
                break;

            case 4:
                myTree.display_inorder();
                break;

            case 5:
                std::cout << "Height of the tree: " << myTree.find_height() << std::endl;
                break;

            case 6:
                myTree.display_bfs();
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
