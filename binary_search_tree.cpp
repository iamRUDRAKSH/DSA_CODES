#include<iostream>
#include<stack>
using namespace std;

// Node structure for the Binary Search Tree
struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val): data(val), left(nullptr), right(nullptr) {}
};

// Binary Search Tree class encapsulating all standard operations
class Binary_Search_Tree{

    Node* root;

public:
    // Constructor initializes the root to nullptr
    Binary_Search_Tree(): root(nullptr) {}

    // Getter function for the root node
    Node* getRoot(){
        return root;
    }

    // Inserts a node with the given value into the BST
    void insertNode(int val){
        Node* nn = new Node(val);
        if(!root){
            root = nn;
            return;
        }
        Node* temp = root;
        while(temp){
            if(temp->data > val){
                if(!temp->left){
                    temp->left = nn;
                    return;
                }
                temp = temp->left;
            }
            else if(temp->data < val){
                if(!temp->right){
                    temp->right = nn;
                    return;
                }
                temp = temp->right;
            }
            else{
                // Duplicate value insertion is not allowed
                cout << "Value already exists.\n";
                return;
            }
        }
    }

    // Performs Preorder traversal (Root, Left, Right)
    void Preorder(Node* node){
        if(!node)
            return;
        cout << node->data << " ";
        Preorder(node->left);
        Preorder(node->right);
    }

    // Performs Inorder traversal (Left, Root, Right)
    void Inorder(Node* node){
        if(!node)
            return;
        Inorder(node->left);
        cout << node->data << " ";
        Inorder(node->right);
    }

    // Performs Postorder traversal (Left, Right, Root)
    void Postorder(Node* node){
        if(!node)
            return;
        Postorder(node->left);
        Postorder(node->right);
        cout << node->data << " ";
    }

    // Prints all the leaf nodes of the BST
    void leafNodes(Node* node) {
        if (!node) 
            return;
    
        if (!node->left && !node->right) { 
            cout << node->data << " "; // Node with no children
            return;
        }
    
        // Recursive calls for left and right subtrees
        leafNodes(node->left);
        leafNodes(node->right);
    }
    
    // Searches for a value in the BST
    void search(int val){
        if(!root){
            cout << "Tree is empty!\n";
            return;
        }
        Node* temp = root;
        while(temp){
            if(temp->data == val){
                cout << val << " FOUND\n";
                return;
            }
            else if(temp->data > val)
                temp = temp->left;
            else
                temp = temp->right;
        }
        cout << val << " NOT FOUND\n";
    }

    // Deletes a node with the given value from the BST
    void deleteNode(int val){
        Node* temp = root;
        Node* parent = nullptr;

        // Locate the node and keep track of its parent
        while(temp && temp->data != val){
            parent = temp;
            temp = (temp->data < val) ? temp->right : temp->left;
        }
        
        if(!temp){
            cout << "Node does not exist.\n";
            return;
        }

        // Case 1: Node has 0 or 1 child
        if(!temp->left || !temp->right){
            Node* child = temp->left ? temp->left : temp->right;
            if(!parent) 
                root = child; // Deleting root node
            else if(parent->left == temp) 
                parent->left = child;
            else 
                parent->right = child;
            delete temp;
        } 
        // Case 2: Node has 2 children
        else {
            // Find inorder successor (smallest in right subtree)
            Node* succParent = temp;
            Node* succ = temp->right;
            while(succ->left){
                succParent = succ;
                succ = succ->left;
            }
            temp->data = succ->data; // Copy successor's value

            // Delete the successor node
            Node* child = succ->right;
            if(succParent->left == succ)
                succParent->left = child;
            else
                succParent->right = child;
            delete succ;
        }
    }
};

int main() {
    Binary_Search_Tree bst;

    // Inserting nodes into the BST
    bst.insertNode(10);
    bst.insertNode(5);
    bst.insertNode(15);
    bst.insertNode(3);
    bst.insertNode(7);
    bst.insertNode(12);
    bst.insertNode(18);

    // Displaying tree traversals
    cout << "Preorder Traversal: ";
    bst.Preorder(bst.getRoot());
    cout << endl;

    cout << "Inorder Traversal: ";
    bst.Inorder(bst.getRoot());
    cout << endl;

    cout << "Postorder Traversal: ";
    bst.Postorder(bst.getRoot());
    cout << endl;

    // Displaying only the leaf nodes
    cout << "Leaf Nodes: ";
    bst.leafNodes(bst.getRoot());
    cout << endl;

    // Searching for elements
    bst.search(0);   // Not present
    bst.search(7);   // Present

    // Deleting a node and re-checking
    bst.deleteNode(7);
    bst.search(7);   // Should not be found now

    return 0;
}
