#include <iostream>
using namespace std;

// Node structure representing each element in the circular linked list
struct Node {
    int data;
    Node* next;

    // Constructor to initialize node with given value
    Node(int val): data(val), next(nullptr) {}
};

class Circular_ll {
    Node* head;  // Pointer to the head (first) node

public:
    // Constructor initializes an empty list
    Circular_ll(): head(nullptr) {}

    // Function to add a node at the end of the list
    void append(int data) {
        Node* nn = new Node(data);
        
        // If list is empty, initialize head and make it circular
        if (!head) {
            head = nn;
            nn->next = head;
            return;
        }

        // Traverse to the last node
        Node* t = head;
        while (t->next != head)
            t = t->next;

        // Insert new node at the end and maintain circular link
        t->next = nn;
        nn->next = head;
    }

    // Function to display the circular linked list
    void printlist() {
        if (!head) {
            cout << "List is empty" << endl;
            return;
        }

        Node* t = head;
        do {
            cout << t->data << "->";
            t = t->next;
        } while (t != head);

        cout << "HEAD" << endl;  // Indicates the circular connection
    }

    // Function to delete the head node from the circular linked list
    void pop() {
        if (!head) {
            cout << "List is empty." << endl;
            return;
        }

        // Special case: only one node in the list
        if (head->next == head) {
            delete head;
            head = nullptr;
            return;
        }

        // Traverse to the last node
        Node* t = head;
        while (t->next != head)
            t = t->next;

        // Update head and maintain circular link
        Node* temp = head;
        head = head->next;
        t->next = head;
        delete temp;  // Delete old head
    }
};

int main() {
    Circular_ll cll;

    // Inserting nodes into circular linked list
    cll.append(1);
    cll.append(2);
    cll.append(3);

    // Display list
    cll.printlist();  // Output: 1->2->3->HEAD

    // Delete head node
    cll.pop();

    // Display updated list
    cll.printlist();  // Output: 2->3->HEAD

    return 0;
}