#include<iostream>
#include<stack>
#include<queue>
using namespace std;

// Node structure for the Binary Tree
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val): data(val), left(nullptr), right(nullptr) {}
};

// Binary Tree class supporting various traversal and utility methods
class Binary_Tree {

    Node* root;

public:
    // Constructor initializes root to nullptr
    Binary_Tree(): root(nullptr) {}

    // Getter for root node
    Node* getRoot() {
        return root;
    }

    // Insert node in level-order fashion (BFS-style)
    void insertNode(int val) {
        Node* newNode = new Node(val);
        if (!root) {
            root = newNode;
            return;
        }

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* temp = q.front();
            q.pop();

            if (!temp->left) {
                temp->left = newNode;
                return;
            } else {
                q.push(temp->left);
            }

            if (!temp->right) {
                temp->right = newNode;
                return;
            } else {
                q.push(temp->right);
            }
        }
    }
    
    // Print all leaf nodes (nodes with no children)
    void leafNodes() {
        if (!root)
            return;

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* temp = q.front();
            q.pop();

            if (!temp->left && !temp->right)
                cout << temp->data << " ";

            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);   
        }
    }

    // Calculate the height of the tree recursively
    int findHeight(Node* node) {
        if (!node) 
            return -1;  // Convention: height of empty tree is -1

        int leftHeight = findHeight(node->left);
        int rightHeight = findHeight(node->right);

        return 1 + max(leftHeight, rightHeight);
    }

    // Count the total number of nodes in the tree recursively
    int countNodes(Node* node) {
        if (!node)
            return 0;

        return 1 + countNodes(node->left) + countNodes(node->right);
    }

    // Iterative Postorder traversal using two stacks
    void Postorder() {
        if (!root) return;

        stack<Node*> s1, s2;
        s1.push(root);

        while (!s1.empty()) {
            Node* curr = s1.top();
            s1.pop();
            s2.push(curr);

            if (curr->left) s1.push(curr->left);
            if (curr->right) s1.push(curr->right);
        }

        while (!s2.empty()) {
            cout << s2.top()->data << " ";
            s2.pop();
        }
    }

    // Iterative Inorder traversal using a stack
    void Inorder() {
        stack<Node*> s;
        Node* curr = root;

        while (curr || !s.empty()) {
            while (curr) {
                s.push(curr);
                curr = curr->left;
            }

            curr = s.top();
            s.pop();
            cout << curr->data << " ";
            curr = curr->right;
        }
    }

    // Iterative Preorder traversal using a stack
    void Preorder() {
        if (!root)
            return;

        stack<Node*> s;
        s.push(root);

        while (!s.empty()) {
            Node* curr = s.top();
            s.pop();
            cout << curr->data << " ";

            // Push right child first so left is processed first
            if (curr->right) s.push(curr->right);
            if (curr->left) s.push(curr->left);
        }
    }

    // Level-order traversal using a queue (BFS)
    void Levelorder() {
        if (!root)
            return;

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();
            cout << curr->data << " ";

            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }
    }
};

int main() {
    Binary_Tree tree;

    // Inserting nodes to form a complete binary tree
    tree.insertNode(1);
    tree.insertNode(2);
    tree.insertNode(3);
    tree.insertNode(4);
    tree.insertNode(5);
    tree.insertNode(6);
    tree.insertNode(7);

    // Display leaf nodes
    cout << "Leaf nodes: ";
    tree.leafNodes();
    cout << endl;

    // Calculate and print tree height
    int height = tree.findHeight(tree.getRoot());
    cout << "Height of the tree: " << height << endl;

    // Count and print total nodes
    int totalNodes = tree.countNodes(tree.getRoot());
    cout << "Total number of nodes: " << totalNodes << endl;

    // Perform Preorder traversal
    cout << "Preorder traversal: ";
    tree.Preorder();
    cout << endl;

    // Perform Inorder traversal
    cout << "Inorder traversal: ";
    tree.Inorder();
    cout << endl;

    // Perform Postorder traversal
    cout << "Postorder traversal: ";
    tree.Postorder();
    cout << endl;

    // Perform Level-order traversal
    cout << "Levelorder traversal: ";
    tree.Levelorder();
    cout << endl;

    return 0;
}
