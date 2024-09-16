#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *prev;
    Node *next;

    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

class DLL{
    Node *head;
    public:
    DLL() : head(nullptr) {};
    ~DLL() {
        while (head != nullptr) {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }
    void insertAtEnd(int val){
        Node *nn = new Node(val);
        if (!head)
            head = nn;
        else {
            Node *t = head;
            while (t->next)
                t = t->next;
            nn->prev = t;
            t->next = nn;
        }
    }
    void remove(int val) {
        if (!head) {
            cout << "List is empty!!" << endl;
            return;
        }

        // Remove nodes at the head with matching value
        while (head && head->data == val) {
            Node *temp = head;
            head = head->next;
            if (head) head->prev = nullptr;
            delete temp;
        }

        Node *t = head;
        while (t) {
            if (t->data == val) {
                Node *temp = t;
                if (t->next) {
                    t->next->prev = t->prev;
                }
                if (t->prev) {
                    t->prev->next = t->next;
                }
                t = t->next; // Move to the next node
                delete temp; // Delete the current node
            } else {
                t = t->next; // Move to the next node
            }
        }
    }

    void insertAtHead(int val){
        Node *nn = new Node(val);
        if (!head)
            head = nn;
        else{
            nn->next = head;
            head->prev = nn;
            head = nn;
        }
    }
    void insertBefore(int val, int after){
        Node *nn = new Node(val);
        Node *t = head;
        while(t && t->data != after)
            t = t->next;
        if(!t)
            cout<<"Element not found!!"<<endl;
        else{
            if(t == head){
                insertAtHead(val);
            }
            else{
                nn->next = t;
                t->prev->next = nn;
                nn->prev = t->prev;
                t->prev = nn;
            }
        }
    }
    void search(int val){
        Node *t = head;
        int count = 1;
        while(t){
            if(t->data == val)
                cout<<"Element found at position "<<count<<endl;
            t = t->next;
            count++;
        }
    }
    void pop(){
        if(!head)
            cout<<"List is empty!!"<<endl;
        else if(head->next == nullptr){
            delete head;
            head = nullptr;
        }
        else{
            Node *t = head;
            while(t->next){
                t = t->next;
            }
            t->prev->next = nullptr;
            delete t;
        }
    }
    void printList(){
        Node *t = head;
        while(t){
            cout<<t->data<<"->";
            t = t->next;
        }
        cout<<"NULL"<<endl;
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
