#include<iostream>
#include<stack>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val): data(val), left(nullptr), right(nullptr) {}
};

class Binary_Search_Tree{

    Node* root;

    public:
    Binary_Search_Tree(): root(nullptr) {}

    Node* getRoot(){
        return root;
    }

    void insertNode(int val){
        Node* nn = new Node(val);
        if(!root){
            root = nn;
            return;
        }
        Node* temp = root;
        while(temp){
            if(temp->data >= val){
                if(!temp->left){
                    temp->left = nn;
                    return;
                }
                temp = temp->left;
            }
            else{
                if(!temp->right){
                    temp->right = nn;
                    return;
                }
                temp = temp->right;
            }
        }
    }

    void Preorder(Node* node){
        if(!node)
            return;
        
        cout << node->data << " ";
        Preorder(node->left);
        Preorder(node->right);
    }

    void Inorder(Node* node){
        if(!node)
            return;
        
        Inorder(node->left);
        cout << node->data << " ";
        Inorder(node->right);
    }

    void Postorder(Node* node){
        if(!node)
            return;
        
        Postorder(node->left);
        Postorder(node->right);
        cout << node->data << " ";
    }

    void leafNodes(Node* node) {
        if (!node) 
            return; // Base case: If node is null, return
    
        if (!node->left && !node->right) { 
            cout << node->data << " "; // Print leaf node
            return;
        }
    
        leafNodes(node->left);  // Recur for left subtree
        leafNodes(node->right); // Recur for right subtree
    }
    
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

    Node* findMin(Node* node){
        while (node->left)
            node = node->left;
        return node;
    }

    void deleteNode(int val){
        Node* temp = root;
        Node* parent = nullptr;

        while(temp && temp->data != val){
            parent = temp;
            if(temp->data < val)
                temp = temp->right;
            else if(temp->data > val)
                temp = temp->left;
        }
        
        if(!temp){
            cout << "Node does not exist.\n";
            return;
        }

        if(!temp->left){
            if(!parent){
                root = temp->right;
                delete temp;
                return;
            }
            if(parent->left == temp)
                parent->left = temp->right;
            else
                parent->right = temp->right;
            delete temp;
        }
        else if(!temp->right){
            if(!parent){
                root = temp->left;
                delete temp;
                return;
            }
            if(parent->left == temp)
                parent->left = temp->left;
            else
                parent->right = temp->left;
            delete temp;
        }
        else{
            Node* succesor = findMin(temp->right);
            int succesorVal = succesor->data;
            deleteNode(succesorVal);
            temp->data = succesorVal;
        }
    }
};

int main() {
    Binary_Search_Tree bst;

    // Inserting nodes into the binary search tree
    bst.insertNode(10);
    bst.insertNode(5);
    bst.insertNode(15);
    bst.insertNode(3);
    bst.insertNode(7);
    bst.insertNode(12);
    bst.insertNode(18);

    // Displaying tree traversal
    cout << "Preorder Traversal: ";
    bst.Preorder(bst.getRoot());
    cout << endl;

    cout << "Inorder Traversal: ";
    bst.Inorder(bst.getRoot());
    cout << endl;

    cout << "Postorder Traversal: ";
    bst.Postorder(bst.getRoot());
    cout << endl;

    // Displaying leaf nodes
    cout << "Leaf Nodes: ";
    bst.leafNodes(bst.getRoot());
    cout << endl;

    bst.search(0);
    bst.search(7);

    bst.deleteNode(7);
    bst.search(7);

    return 0;
}