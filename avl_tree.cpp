#include <iostream>
using namespace std;

// Node structure for AVL Tree
struct Node {
    int data;
    Node* left;
    Node* right;
    int height;

    // Constructor initializes a new node
    Node(int val) : data(val), left(nullptr), right(nullptr), height(1) {}
};

class AVLTree {
private:
    Node* root;  // Root of the AVL Tree

    // Utility to get height of a node
    int height(Node* node) {
        return node ? node->height : 0;
    }

    // Utility to get balance factor of a node
    int getBalanceFactor(Node* node) {
        return node ? height(node->left) - height(node->right) : 0;
    }

    // Right rotation (LL case)
    Node* rotateRight(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;

        // Perform rotation
        x->right = y;
        y->left = T2;

        // Update heights
        y->height = max(height(y->left), height(y->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;

        return x;  // Return new root
    }

    // Left rotation (RR case)
    Node* rotateLeft(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;

        // Perform rotation
        y->left = x;
        x->right = T2;

        // Update heights
        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;

        return y;  // Return new root
    }

    // Recursive insert with balancing
    Node* insert(Node* node, int val) {
        if (!node)
            return new Node(val);  // Base case

        if (val < node->data)
            node->left = insert(node->left, val);
        else if (val > node->data)
            node->right = insert(node->right, val);
        else
            return node;  // Duplicate values not allowed

        // Update height of this ancestor node
        node->height = 1 + max(height(node->left), height(node->right));

        // Get balance factor to check for unbalance
        int balance = getBalanceFactor(node);

        // Perform rotations for unbalanced cases
        if (balance > 1 && val < node->left->data) return rotateRight(node);       // LL
        if (balance < -1 && val > node->right->data) return rotateLeft(node);      // RR
        if (balance > 1 && val > node->left->data) {                                // LR
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }
        if (balance < -1 && val < node->right->data) {                              // RL
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }

        return node;  // Return the unchanged node pointer
    }

    // Find node with minimum value (used in deletion)
    Node* findMin(Node* node) {
        while (node->left)
            node = node->left;
        return node;
    }

    // Recursive delete with balancing
    Node* deleteNode(Node* node, int val) {
        if (!node)
            return node;

        if (val < node->data)
            node->left = deleteNode(node->left, val);
        else if (val > node->data)
            node->right = deleteNode(node->right, val);
        else {
            // Node to be deleted found
            if (!node->left || !node->right) {
                Node* temp = node->left ? node->left : node->right;
                delete node;
                return temp;
            } else {
                Node* temp = findMin(node->right);
                node->data = temp->data;
                node->right = deleteNode(node->right, temp->data);
            }
        }

        // If the tree had only one node
        if (!node)
            return node;

        // Update height
        node->height = 1 + max(height(node->left), height(node->right));

        // Get balance factor
        int balance = getBalanceFactor(node);

        // Perform rotations for unbalanced cases
        if (balance > 1 && getBalanceFactor(node->left) >= 0) return rotateRight(node);      // LL
        if (balance > 1 && getBalanceFactor(node->left) < 0) {                                // LR
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }
        if (balance < -1 && getBalanceFactor(node->right) <= 0) return rotateLeft(node);      // RR
        if (balance < -1 && getBalanceFactor(node->right) > 0) {                              // RL
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }

        return node;
    }

    // Recursive search
    bool search(Node* node, int val) {
        if (!node)
            return false;
        if (node->data == val)
            return true;
        if (val < node->data)
            return search(node->left, val);
        return search(node->right, val);
    }

    // In-order traversal (used to display the tree)
    void inorder(Node* node) {
        if (!node)
            return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

public:
    // Constructor
    AVLTree() : root(nullptr) {}

    // Public interfaces
    void insert(int val) {
        root = insert(root, val);
    }

    void deleteNode(int val) {
        root = deleteNode(root, val);
    }

    bool search(int val) {
        return search(root, val);
    }

    void display() {
        inorder(root);
        cout << endl;
    }
};

int main() {
    AVLTree tree;

    // Insert nodes
    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(40);
    tree.insert(50);
    tree.insert(25);

    cout << "Inorder traversal after insertions: ";
    tree.display();

    // Delete a node
    tree.deleteNode(30);
    cout << "Inorder traversal after deleting 30: ";
    tree.display();

    // Search for nodes
    cout << "Searching for 25: " << (tree.search(25) ? "Found\n" : "Not Found\n");
    cout << "Searching for 30: " << (tree.search(30) ? "Found\n" : "Not Found\n");

    return 0;
}