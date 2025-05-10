#include <iostream>
using namespace std;

class Stack {
    int top;
    int size;
    int* arr;

public:
    // Constructor
    Stack(int n) {
        size = n;
        top = -1;
        arr = new int[size];
    }

    // Destructor
    ~Stack() {
        delete[] arr;
    }

    // Check if stack is empty
    bool isEmpty() {
        return top == -1;
    }

    // Check if stack is full
    bool isFull() {
        return top == size - 1;
    }

    // Peek at the top element
    int Top() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return arr[top];
    }

    // Push an element
    void push(int val) {
        if (isFull()) {
            cout << "Stack is full" << endl;
            return;
        }
        arr[++top] = val;
    }

    // Pop the top element
    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return;
        }
        top--;
    }

    // Optional: Display stack contents
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return;
        }
        cout << "Stack (top to bottom): ";
        for (int i = top; i >= 0; --i)
            cout << arr[i] << " ";
        cout << endl;
    }
};

// Driver code
int main() {
    Stack s(5);
    s.push(10);
    s.push(20);
    cout << "Top: " << s.Top() << endl;
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);  // Should print "Stack is full"
    cout << "Top after push: " << s.Top() << endl;
    s.pop();
    cout << "Top after pop: " << s.Top() << endl;
    s.display(); // Optional

    return 0;
}