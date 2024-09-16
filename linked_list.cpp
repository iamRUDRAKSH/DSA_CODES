#include<iostream>
using namespace std;

// Node structure representing each element in the linked list
struct Node {
    int data;       // Data stored in the node
    Node* next;     // Pointer to the next node

    // Constructor to initialize node with data and set the next pointer to null
    Node(int value) : data(value), next(nullptr) {}
};

// LinkedList class to manage the operations of the linked list
class LinkedList {
private:
    Node* head;    // Pointer to the head (first node) of the list
public:
    // Constructor to initialize the linked list with an empty head
    LinkedList() : head(nullptr) {}

    // Function to append a new node with a given value at the end of the list
    void append(int value) {
        Node* nn = new Node(value);  // Create a new node
        if (!head)                   // If the list is empty, set the new node as the head
            head = nn;
        else {
            Node* t = head;          // Traverse to the end of the list
            while (t->next != nullptr)
                t = t->next;
            t->next = nn;            // Append the new node at the end
        }
    }

    // Function to print the contents of the list
    void printlist() {
        if (!head)
            cout << "List is empty" << endl;
        else {
            Node* t = head;          // Start from the head and print each node's data
            while (t) {
                cout << t->data << "->";
                t = t->next;
            }
            cout << "Null" << endl;  // Indicate the end of the list
        }
    }

    // Function to search for a node with a given value
    Node* search(int value) {
        Node* t = head;
        Node* prev = nullptr;
        while (t) {
            if (t->data == value) {
                cout << "Element " << value << " found" << endl;
                return t;            // Return the node if found
            }
            prev = t;
            t = t->next;
        }
        // If not found, return the last element
        cout << "Element " << value << " not found. Returning last element." << endl;
        return prev;                 // Return the last node if not found
    }

    // Function to replace a node's value, or append if the value is not found
    void replace(int existing, int value) {
        Node* find = search(existing);
        if (find) {
            find->data = value;      // Replace the value if found
        } else {
            cout << "Element " << existing << " not found. Adding " << value << " to the end of the list." << endl;
            find->next = new Node(value);  // Add new node at the end if not found
        }
    }

    // Function to insert a new node with value after a node with a given existing value
    void insertNext(int existing, int value) {
        Node* find = search(existing);
        if (find) {
            Node* nn = new Node(value);
            nn->next = find->next;  // Insert the new node after the found node
            find->next = nn;
        } else {
            cout << "Element " << existing << " not found. Adding " << value << " to the end of the list." << endl;
            find->next = new Node(value);  // Add new node at the end if the node is not found
        }
    }

    // Function to remove a node with a specific value from the list
    void remove(int value) {
        if (!head) {
            cout << "Playlist is empty." << endl;
            return;
        }
        // Remove head nodes that match the value
        while (head && head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        // Remove matching nodes in the rest of the list
        Node* current = head;
        while (current && current->next) {
            if (current->next->data == value) {
                Node* temp = current->next;
                current->next = current->next->next;
                delete temp;
            } else {
                current = current->next; // Only move to next if no deletion
            }
        }
    }

    // Function to remove the first node from the list
    void pop() {
        if (!head) {
            cout << "List is empty." << endl;
            return;
        }
        Node* t = head;
        head = head->next;  // Move the head to the next node
        delete t;           // Delete the original head
    }
    
    // Function to reverse the entire list
    void reverse() {
        if (!head) {
            cout << "List is empty." << endl;
            return;
        }
        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;
        // Traverse and reverse the pointers
        while (current) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;  // Update head to the new first node (last node of original list)
    }

    // Destructor to free up allocated memory
    ~LinkedList() {
        Node* current = head;
        Node* nn = nullptr;
        while (current) {
            nn = current->next;
            delete current;
            current = nn;
        }
    }
};

// Main function to test the LinkedList class
int main() {
    LinkedList list;
    list.append(21);               // Add 21 to the list
    list.append(41);               // Add 41 to the list
    list.printlist();              // Print the list: 21->41->Null
    list.append(51);               // Add 51 to the list
    list.insertNext(21, 31);       // Insert 31 after 21
    list.replace(41, 61);          // Replace 41 with 61
    list.printlist();              // Print the list: 21->31->61->51->Null
    list.replace(71, 81);          // Since 71 is not found, 81 is added at the end
    list.insertNext(71, 91);       // Insert 91 after the last element (81)
    list.printlist();              // Print the list: 21->31->61->51->81->91->Null
    list.remove(41);               // Remove 41 (but it has already been replaced with 61)
    list.remove(81);               // Remove 81
    list.printlist();              // Print the list: 21->31->61->51->91->Null
    list.pop();                    // Remove the first element (21)
    list.printlist();              // Print the list: 31->61->51->91->Null
    return 0;
}