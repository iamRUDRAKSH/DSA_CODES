#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

class Queue {
    Node* front;
    Node* rear;

public:
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    ~Queue() {
        // Destructor to clean up memory
        while (!isEmpty()) {
            dequeue();
        }
    }

    bool isEmpty() {
        return front == nullptr;
    }

    int Front() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;  // Return a sentinel value
        }
        return front->data;
    }

    void enqueue(int val) {
        Node* newNode = new Node(val);
        if (isEmpty()) {
            front = newNode;
            rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        Node* temp = front;
        front = front->next;
        if (front == nullptr) { // If the queue becomes empty after dequeue
            rear = nullptr;
        }
        delete temp;
    }

    void printQueue() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        Node* temp = front;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    cout << "Front element: " << q.Front() << endl;  // Output should be 1
    q.printQueue();
    
    q.dequeue();
    cout << "Front element after dequeue: " << q.Front() << endl;  // Output should be 2
    q.dequeue();
    q.dequeue();
    q.dequeue();  // Should display "Queue is empty"
    q.printQueue();
    
    return 0;
}