#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    int height;

    Node(int val) : data(val), left(nullptr), right(nullptr), height(1) {}
};

class AVLTree {
private:
    Node* root;

    int height(Node* node) {
        if (!node)
            return 0;
        return node->height;
    }

    int getBalanceFactor(Node* node) {
        if (!node)
            return 0;
        return height(node->left) - height(node->right);
    }

    Node* rotateRight(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = max(height(y->left), height(y->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;

        return x;  // New root
    }

    Node* rotateLeft(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;

        return y;  // New root
    }

    Node* insert(Node* node, int val) {
        if (!node) return new Node(val);

        if (val < node->data)
            node->left = insert(node->left, val);
        else if (val > node->data)
            node->right = insert(node->right, val);
        else
            return node;  // Duplicates not allowed

        node->height = 1 + max(height(node->left), height(node->right));
        int balance = getBalanceFactor(node);

        // **Balancing Cases**
        if (balance > 1 && val < node->left->data) return rotateRight(node);  // LL
        if (balance < -1 && val > node->right->data) return rotateLeft(node);  // RR
        if (balance > 1 && val > node->left->data) {  // LR
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }
        if (balance < -1 && val < node->right->data) {  // RL
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }

        return node;
    }

    Node* findMin(Node* node) {
        while (node->left)
            node = node->left;
        return node;
    }

    Node* deleteNode(Node* node, int val) {
        if (!node) return node;

        if (val < node->data)
            node->left = deleteNode(node->left, val);
        else if (val > node->data)
            node->right = deleteNode(node->right, val);
        else {
            if (!node->left || !node->right) {  // 0 or 1 child
                Node* temp = node->left ? node->left : node->right;
                delete node;
                return temp;
            } else {  // 2 children
                Node* temp = findMin(node->right);
                node->data = temp->data;
                node->right = deleteNode(node->right, temp->data);
            }
        }

        if (!node) return node;  // If tree had only one node

        node->height = 1 + max(height(node->left), height(node->right));
        int balance = getBalanceFactor(node);

        // **Balancing Cases**
        if (balance > 1 && getBalanceFactor(node->left) >= 0) return rotateRight(node);  // LL
        if (balance > 1 && getBalanceFactor(node->left) < 0) {  // LR
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }
        if (balance < -1 && getBalanceFactor(node->right) <= 0) return rotateLeft(node);  // RR
        if (balance < -1 && getBalanceFactor(node->right) > 0) {  // RL
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }
        return node;
    }

    bool search(Node* node, int val) {
        if (!node) return false;
        if (node->data == val) return true;
        if (val < node->data) return search(node->left, val);
        return search(node->right, val);
    }

    void inorder(Node* node) {
        if (!node) return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

public:
    AVLTree() : root(nullptr) {}

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

    // Search for a node
    cout << "Searching for 25: " << (tree.search(25) ? "Found\n" : "Not Found\n");
    cout << "Searching for 30: " << (tree.search(30) ? "Found\n" : "Not Found\n");

    return 0;
}
