#include <iostream>
using namespace std;

// Node structure to represent each directory in the Red-Black Tree
struct Node {
    string name;  // Name of the node (directory)
    int color;    // Color of the node: 0 = Red, 1 = Black
    Node* left;   // Pointer to the left child
    Node* right;  // Pointer to the right child
    Node* parent; // Pointer to the parent node

    // Constructor to initialize the node with a name and default color (Red)
    Node(string n) : name(n), color(0), left(nullptr), right(nullptr), parent(nullptr) {}
};

class RedBlackTree {
    Node* root;  // Pointer to the root node of the tree

    // Helper function to find the minimum node in a subtree
    Node* minimum(Node* node) {
        while (node->left)  // Keep traversing left to find the minimum
            node = node->left;
        return node;
    }

    // Helper function to replace one subtree with another
    void transplant(Node* u, Node* v) {
        if (!u->parent)  // If u is the root, make v the new root
            root = v;
        else if (u == u->parent->left)  // If u is the left child, replace it with v
            u->parent->left = v;
        else  // If u is the right child, replace it with v
            u->parent->right = v;
        if (v)
            v->parent = u->parent;  // Set the parent of v
    }

public:
    // Constructor to initialize the tree with a null root
    RedBlackTree() { root = nullptr; }

    // Function to perform a right rotation on a node
    void rotate_right(Node*& nn) {
        Node* nn_left = nn->left;
        nn->left = nn_left->right;
        if (nn->left) nn->left->parent = nn;
        nn_left->parent = nn->parent;
        if (!nn->parent) root = nn_left;
        else if (nn == nn->parent->left) nn->parent->left = nn_left;
        else nn->parent->right = nn_left;
        nn_left->right = nn;
        nn->parent = nn_left;
    }

    // Function to perform a left rotation on a node
    void rotate_left(Node*& x) {
        Node* y = x->right;
        x->right = y->left;
        if (x->right) x->right->parent = x;
        y->parent = x->parent;
        if (!x->parent) root = y;
        else if (x == x->parent->right) x->parent->right = y;
        else x->parent->left = y;
        y->left = x;
        x->parent = y;
    }

    // Function to fix any violations of Red-Black Tree properties after insertion
    void fixViolation(Node* nn) {
        Node* nn_pp = nullptr;
        Node* nn_gp = nullptr;

        // While node is not root and there is a color violation (two consecutive reds)
        while ((nn != root) && (nn->color == 0) && (nn->parent->color == 0)) {
            nn_pp = nn->parent;
            nn_gp = nn->parent->parent;

            if (nn_pp == nn_gp->left) {
                Node* nn_un = nn_gp->right;

                // Case 1: Uncle node is red, recolor and move up the tree
                if (nn_un && nn_un->color == 0) {
                    nn_gp->color = 1;
                    nn_pp->color = 1;
                    nn_un->color = 1;
                    nn = nn_gp;  // Move to grandparent
                } else {
                    // Case 2: Node is a right child, perform left rotation
                    if (nn == nn_pp->right) {
                        rotate_left(nn_pp);
                        nn = nn_pp;
                        nn_pp = nn->parent;
                    }
                    // Perform right rotation on the grandparent and swap colors
                    rotate_right(nn_gp);
                    swap(nn_pp->color, nn_gp->color);
                    nn = nn_pp;
                }
            } else {
                Node* nn_un = nn_gp->left;

                // Case 1: Uncle node is red, recolor and move up the tree
                if (nn_un && nn_un->color == 0) {
                    nn_gp->color = 1;
                    nn_pp->color = 1;
                    nn_un->color = 1;
                    nn = nn_gp;  // Move to grandparent
                } else {
                    // Case 2: Node is a left child, perform right rotation
                    if (nn == nn_pp->left) {
                        rotate_right(nn_pp);
                        nn = nn_pp;
                        nn_pp = nn->parent;
                    }
                    // Perform left rotation on the grandparent and swap colors
                    rotate_left(nn_gp);
                    swap(nn_pp->color, nn_gp->color);
                    nn = nn_pp;
                }
            }
        }

        // Set root to black
        root->color = 1;
    }

    // Function to add a node (directory) to the tree
    void addNode(const string& n) {
        Node* nn = new Node(n);  // Create a new node with the given name
        Node* y = nullptr;
        Node* x = root;

        // Find the appropriate position in the tree
        while (x != nullptr) {
            y = x;
            if (nn->name < x->name) x = x->left;
            else if (nn->name > x->name) x = x->right;
            else {
                cout << "This node already exists.\n";
                return; // Duplicate
            }
        }

        // Set the parent of the new node
        nn->parent = y;
        if (!y) root = nn;
        else if (nn->name < y->name) y->left = nn;
        else y->right = nn;

        // Fix any violations of Red-Black Tree properties
        fixViolation(nn);
    }

    // Function to delete a node from the tree
    void deleteNode(const string& name) {
        Node* z = root;

        // Search for the node to delete
        while (z != nullptr && z->name != name) {
            if (name < z->name) z = z->left;
            else z = z->right;
        }

        // If the node is not found, print an error message
        if (!z) {
            cout << "Node not found.\n";
            return;
        }

        Node* y = z;
        int y_original_color = y->color;
        Node* x;

        // Case 1: Node has only one child or no children
        if (!z->left) {
            x = z->right;
            transplant(z, z->right);
        } else if (!z->right) {
            x = z->left;
            transplant(z, z->left);
        } else {
            // Case 2: Node has two children, find the successor
            y = minimum(z->right);
            y_original_color = y->color;
            x = y->right;

            if (y->parent == z) {
                if (x) x->parent = y;
            } else {
                transplant(y, y->right);
                y->right = z->right;
                if (y->right) y->right->parent = y;
            }

            transplant(z, y);
            y->left = z->left;
            if (y->left) y->left->parent = y;
            y->color = z->color;
        }

        delete z;  // Delete the node
        cout << "Node '" << name << "' deleted.\n";
    }

    // Helper function to perform an in-order traversal of the tree
    void inorderHelper(Node* root, int depth = 0) {
        if (root == nullptr) return;
        inorderHelper(root->left, depth + 1);  // Traverse left subtree
        cout << string(depth * 2, ' ') << (root->color == 0 ? "[R] " : "[B] ") << root->name << "\n";  // Print the node
        inorderHelper(root->right, depth + 1);  // Traverse right subtree
    }

    // Function to display the tree structure in an in-order fashion
    void display() {
        cout << "\nTree Structure (Red-Black Tree):\n";
        if (!root)
            cout << "Empty tree.\n";
        else
            inorderHelper(root);
    }
};

int main() {
    RedBlackTree rbTree;  // Create a Red-Black Tree object
    int choice;
    string name;

    // Menu for interacting with the Red-Black Tree
    do {
        cout << "\n--- Tree Menu ---\n";
        cout << "1. Add Node\n";
        cout << "2. Delete Node\n";
        cout << "3. Display Tree Structure\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter node name to add: ";
                cin >> name;
                rbTree.addNode(name);  // Add a new node to the tree
                break;

            case 2:
                cout << "Enter node name to delete: ";
                cin >> name;
                rbTree.deleteNode(name);  // Delete a node from the tree
                break;

            case 3:
                rbTree.display();  // Display the tree structure
                break;

            case 4:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 4);  // Loop until the user chooses to exit

    return 0;
}