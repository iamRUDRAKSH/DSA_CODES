#include<iostream>
using namespace std;

// Node structure for a doubly linked list
struct Node {
    int data;        // Data stored in the node
    Node *prev;      // Pointer to the previous node
    Node *next;      // Pointer to the next node

    // Constructor to initialize node with value and set pointers to nullptr
    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

// Doubly Linked List class
class DLL {
    Node *head;      // Pointer to the head of the list

public:
    // Constructor to initialize an empty list
    DLL() : head(nullptr) {}

    // Destructor to delete all nodes and free memory
    ~DLL() {
        while (head != nullptr) {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }

    // Insert a new node with value at the end of the list
    void insertAtEnd(int val) {
        Node *nn = new Node(val); // Create a new node
        if (!head) {
            head = nn; // If list is empty, new node becomes head
        } else {
            Node *t = head;
            while (t->next) {
                t = t->next; // Traverse to the end of the list
            }
            nn->prev = t;   // Update new node's prev pointer
            t->next = nn;   // Update last node's next pointer
        }
    }

    // Remove all nodes with the specified value
    void remove(int val) {
        if (!head) {
            cout << "List is empty!!" << endl;
            return;
        }

        // Remove nodes from the head if they match the value
        while (head && head->data == val) {
            Node *temp = head;
            head = head->next;
            if (head) head->prev = nullptr; // Update new head's prev pointer
            delete temp;
        }

        Node *t = head;
        while (t) {
            if (t->data == val) {
                Node *temp = t;
                if (t->next) {
                    t->next->prev = t->prev; // Update next node's prev pointer
                }
                if (t->prev) {
                    t->prev->next = t->next; // Update previous node's next pointer
                }
                t = t->next; // Move to the next node
                delete temp; // Delete the current node
            } else {
                t = t->next; // Move to the next node
            }
        }
    }

    // Insert a new node with value at the head of the list
    void insertAtHead(int val) {
        Node *nn = new Node(val); // Create a new node
        if (!head) {
            head = nn; // If list is empty, new node becomes head
        } else {
            nn->next = head;  // Update new node's next pointer
            head->prev = nn;  // Update current head's prev pointer
            head = nn;        // Update head to new node
        }
    }

    // Insert a new node with value before a specified existing node's value
    void insertBefore(int val, int after) {
        Node *nn = new Node(val); // Create a new node
        Node *t = head;
        while (t && t->data != after) {
            t = t->next; // Traverse to find the specified node
        }
        if (!t) {
            cout << "Element not found!!" << endl;
        } else {
            if (t == head) {
                insertAtHead(val); // Insert before the head
            } else {
                nn->next = t;          // Update new node's next pointer
                t->prev->next = nn;   // Update previous node's next pointer
                nn->prev = t->prev;   // Update new node's prev pointer
                t->prev = nn;         // Update found node's prev pointer
            }
        }
    }

    // Search for nodes with the specified value and print their position(s)
    void search(int val) {
        Node *t = head;
        int count = 1;
        while (t) {
            if (t->data == val) {
                cout << "Element found at position " << count << endl;
            }
            t = t->next; // Move to the next node
            count++;
        }
    }

    // Remove the last node in the list
    void pop() {
        if (!head) {
            cout << "List is empty!!" << endl;
        } else if (head->next == nullptr) {
            delete head; // If there's only one node, delete it
            head = nullptr; // Set head to nullptr
        } else {
            Node *t = head;
            while (t->next) {
                t = t->next; // Traverse to the last node
            }
            t->prev->next = nullptr; // Update second-last node's next pointer
            delete t; // Delete the last node
        }
    }

    // Print the entire list
    void printList() {
        Node *t = head;
        while (t) {
            cout << t->data << "->";
            t = t->next; // Move to the next node
        }
        cout << "NULL" << endl; // End of the list
    }
};

int main() {
    DLL list;

    // Test: Insert at the end
    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.insertAtEnd(40);
    cout << "After inserting at the end: 10, 20, 30, 40" << endl;
    list.printList(); // Print the current list
    list.search(30);  // Search for an existing element
    list.search(50);  // Search for a non-existing element

    // Test: Insert at the head
    list.insertAtHead(5);
    list.insertAtHead(1);
    cout << "After inserting at the head: 1, 5" << endl;
    list.printList(); // Print the current list

    // Test: Insert before a given element
    list.insertBefore(25, 30);
    cout << "After inserting 25 before 30" << endl;
    list.printList(); // Print the current list

    // Test: Insert before the head element
    list.insertBefore(0, 1); // Should insert before head
    cout << "After inserting 0 before 1 (head)" << endl;
    list.printList(); // Print the current list

    // Test: Remove an element (removing 20, which exists in the list)
    list.remove(20);
    cout << "After removing 20" << endl;
    list.printList(); // Print the current list

    // Test: Remove element that doesn't exist
    list.remove(100); // Removing non-existent element
    cout << "Attempted to remove 100 (non-existent)" << endl;
    list.printList(); // Print the current list

    // Test: Remove multiple occurrences of an element
    list.insertAtEnd(30); // Add another 30
    list.insertAtEnd(30); // Add yet another 30
    cout << "After adding multiple occurrences of 30" << endl;
    list.printList(); // Print the current list
    list.remove(30);  // Should remove all occurrences of 30
    cout << "After removing all occurrences of 30" << endl;
    list.printList(); // Print the current list
    list.search(30);  // Confirm removal (should not find 30)

    // Test: Pop the last element
    list.pop();
    cout << "After popping the last element" << endl;
    list.printList(); // Print the current list

    // Test: Pop until the list is empty
    list.pop();
    list.pop();
    list.pop();
    list.pop();
    list.pop();
    cout << "After popping until the list is empty" << endl;
    list.printList(); // Print the current list
    list.pop();  // Try popping from an empty list (edge case)

    return 0;
}

