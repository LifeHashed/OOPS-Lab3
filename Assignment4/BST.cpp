#include <iostream>
#include <queue>

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
private:
    TreeNode* root;

    // Helper function to insert a value into the BST
    TreeNode* insert(TreeNode* node, int value) {
        if (node == nullptr) {
            return new TreeNode(value);
        }

        if (value < node->data) {
            node->left = insert(node->left, value);
        } else if (value > node->data) {
            node->right = insert(node->right, value);
        }

        return node;
    }

    // Helper function to find the minimum value node in a subtree
    TreeNode* findMin(TreeNode* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    // Helper function to delete a value from the BST
    TreeNode* deleteNode(TreeNode* node, int value) {
        if (node == nullptr) {
            return nullptr;
        }

        if (value < node->data) {
            node->left = deleteNode(node->left, value);
        } else if (value > node->data) {
            node->right = deleteNode(node->right, value);
        } else {
            if (node->left == nullptr) {
                TreeNode* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                TreeNode* temp = node->left;
                delete node;
                return temp;
            }

            TreeNode* temp = findMin(node->right);
            node->data = temp->data;
            node->right = deleteNode(node->right, temp->data);
        }

        return node;
    }

    // Helper function to search for a value in the BST
    bool search(TreeNode* node, int value) {
        if (node == nullptr) {
            return false;
        }

        if (value == node->data) {
            return true;
        } else if (value < node->data) {
            return search(node->left, value);
        } else {
            return search(node->right, value);
        }
    }

    // Helper function to display the BST using in-order traversal
    void display(TreeNode* node) {
        if (node != nullptr) {
            display(node->left);
            std::cout << node->data << " ";
            display(node->right);
        }
    }

    // Helper function to find the height of the BST
    int findHeight(TreeNode* node) {
        if (node == nullptr) {
            return -1;
        }

        int leftHeight = findHeight(node->left);
        int rightHeight = findHeight(node->right);

        return std::max(leftHeight, rightHeight) + 1;
    }

public:
    // Constructor to initialize an empty BST
    BinarySearchTree() : root(nullptr) {}

    // Insert a value into the BST
    void insert(int value) {
        root = insert(root, value);
    }

    // Delete a value from the BST
    void deleteNode(int value) {
        root = deleteNode(root, value);
    }

    // Search for a value in the BST
    bool search(int value) {
        return search(root, value);
    }

    // Display the BST using in-order traversal
    void display() {
        display(root);
        std::cout << std::endl;
    }

    // Find the height of the BST
    int findHeight() {
        return findHeight(root);
    }

    // Depth-First Search (In-order traversal)
    void dfs() {
        std::cout << "DFS (In-order): ";
        display(root);
        std::cout << std::endl;
    }

    // Breadth-First Search
    void bfs() {
        if (root == nullptr) {
            return;
        }

        std::cout << "BFS: ";
        std::queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* current = q.front();
            q.pop();

            std::cout << current->data << " ";

            if (current->left != nullptr) {
                q.push(current->left);
            }

            if (current->right != nullptr) {
                q.push(current->right);
            }
        }

        std::cout << std::endl;
    }
};

int main() {
    BinarySearchTree bst;

    int choice, value;

    do {
        std::cout << "\nMenu:\n";
        std::cout << "1. Insert element\n";
        std::cout << "2. Delete element\n";
        std::cout << "3. Search element\n";
        std::cout << "4. Display BST\n";
        std::cout << "5. Find Height\n";
        std::cout << "6. DFS (In-order)\n";
        std::cout << "7. BFS\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter value to insert: ";
                std::cin >> value;
                bst.insert(value);
                break;
            case 2:
                std::cout << "Enter value to delete: ";
                std::cin >> value;
                bst.deleteNode(value);
                break;
            case 3:
                std::cout << "Enter value to search: ";
                std::cin >> value;
                std::cout << (bst.search(value) ? "Found" : "Not Found") << std::endl;
                break;
            case 4:
                std::cout << "Binary Search Tree:\n";
                bst.display();
                break;
            case 5:
                std::cout << "Height of the tree: " << bst.findHeight() << std::endl;
                break;
            case 6:
                bst.dfs();
                break;
            case 7:
                bst.bfs();
                break;
        }
    } while (choice != 0);

    return 0;
}
