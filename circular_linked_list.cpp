#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int val): data(val), next(nullptr){};
};

class Circular_ll{
    Node* head;
    public:
    Circular_ll(): head(nullptr){};

    void append(int data){
        Node* nn = new Node(data);
        if(!head){
            head = nn;
            nn->next = head;
            return;
        }
        Node* t = head;          // Traverse to the end of the list
        while (t->next != head)
            t = t->next;
        t->next = nn;
        nn->next = head;
    }

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
        cout << "HEAD" << endl; // Indicates the end of the circular list
    }
    void pop() {
        if (!head) {
            cout << "List is empty." << endl;
            return;
        }
        if (head->next == head) { // Only one node case
            delete head;
            head = nullptr;
            return;
        }
        Node* t = head;
        while (t->next != head) {  // Traverse to the last node
            t = t->next;
        }
        Node* temp = head;
        head = head->next;  // Move head to the next node
        t->next = head;     // Last node points to new head
        delete temp;        // Delete the original head
    }
};

int main(){
    Circular_ll cll;
    cll.append(1);
    cll.append(2);
    cll.append(3);
    cll.printlist();  // Output: 1->2->3->NULL
    cll.pop();
    cll.printlist();  // Output: 2->3->NULL
    return 0;
}