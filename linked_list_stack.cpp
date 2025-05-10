#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val): data(val), next(nullptr) {}
};

class Stack {
public:
    Node* head;

    // Constructor
    Stack() {
        head = nullptr;
    }

    // Destructor to clean up the memory
    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }

    bool isEmpty() {
        return head == nullptr;
    }

    int Top() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return -1;  // Return -1 when stack is empty
        }
        return head->data;
    }

    void push(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }
};

int main() {
    Stack s;
    
    // Checking Top when stack is empty
    cout << s.Top() << endl;  // Output should be -1 (Stack is empty)
    
    s.push(1);
    s.push(2);
    s.push(3);
    
    // Checking Top after pushing some elements
    cout << s.Top() << endl;  // Output should be 3 (Last pushed value)
    
    s.push(4);
    s.push(5);
    
    // Popping one element
    s.pop();
    
    // Checking Top after popping
    cout << s.Top() << endl;  // Output should be 4 (Next top value after pop)
    
    return 0;
}