#include<iostream>
#include<stack>
#include<queue>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val): data(val), left(nullptr), right(nullptr) {}
};

class Binary_Tree{

    Node* root;

    public:
    Binary_Tree(): root(nullptr) {}

    Node* getRoot(){
        return root;
    }

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
    
    void leafNodes(){
        if (!root)
            return;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            Node* temp = q.front();
            q.pop();

            if (!temp->left && !temp->right)
                cout << temp->data << " ";
            
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);   
        }
    }

    int findHeight(Node* node) {
        if (!node) 
            return -1;  // Base case: Empty tree has height -1
    
        int leftHeight = findHeight(node->left);
        int rightHeight = findHeight(node->right);
    
        return 1 + max(leftHeight, rightHeight); // Height = 1 + max(left, right)
    }

    int countNodes(Node* node) {
        if (!node)
            return 0; // Base case: if node is null, return 0
        
        // Recursively count nodes in the left and right subtrees
        return 1 + countNodes(node->left) + countNodes(node->right);
    }

    void Postorder(){
        stack<Node*> s1, s2;
        s1.push(root);
        while(!s1.empty()){
            Node* curr = s1.top();
            s1.pop();
            s2.push(curr);

            if(curr->left) s1.push(curr->left);
            if(curr->right) s1.push(curr->right);
        }
        while(!s2.empty()){
            Node* curr = s2.top();
            cout << curr->data << " ";
            s2.pop();
        }
    }

    void Inorder(){
        stack<Node*> s;
        Node* curr = root;
        while(curr || !s.empty()){

            while(curr){
                s.push(curr);
                curr = curr->left;
            }
            
            curr = s.top();
            s.pop();
            cout << curr->data << " ";

            curr = curr->right;
        }
    }

    void Preorder(){
        if(!root)
            return;
        stack<Node*> s;
        s.push(root);
        while(!s.empty()){
            Node* curr = s.top();
            s.pop();
            cout << curr->data << " ";

            if(curr->right) s.push(curr->right);
            if(curr->left) s.push(curr->left);
        }
    }

    void Levelorder(){
        if(!root)
            return;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            Node* curr = q.front();
            q.pop();
            cout << curr->data << " ";

            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }
    }
    
};

int main() {
    Binary_Tree tree;

    // Inserting nodes
    tree.insertNode(1);
    tree.insertNode(2);
    tree.insertNode(3);
    tree.insertNode(4);
    tree.insertNode(5);
    tree.insertNode(6);
    tree.insertNode(7);

    // Displaying leaf nodes
    cout << "Leaf nodes: ";
    tree.leafNodes();
    cout << endl;

    // Finding height of the tree
    int height = tree.findHeight(tree.getRoot());
    cout << "Height of the tree: " << height << endl;

    // Counting total number of nodes
    int totalNodes = tree.countNodes(tree.getRoot());
    cout << "Total number of nodes: " << totalNodes << endl;

    // Performing Preorder traversal
    cout << "Preorder traversal: ";
    tree.Preorder();
    cout << endl;

    // Performing Inorder traversal
    cout << "Inorder traversal: ";
    tree.Inorder();
    cout << endl;

    // Performing Postorder traversal
    cout << "Postorder traversal: ";
    tree.Postorder();
    cout << endl;

    cout << "Levelorder traversal: ";
    tree.Levelorder();
    cout << endl;

    return 0;
}
