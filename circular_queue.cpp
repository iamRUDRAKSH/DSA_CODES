#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val = 0): data(val), next(nullptr) {}
};

class CircularQueue {
    Node* front;
    Node* rear;

public:
    CircularQueue() : front(nullptr), rear(nullptr) {}

    bool isEmpty() {
        return front == nullptr;
    }

    void enqueue(int val) {
        Node* newNode = new Node(val);
        if (isEmpty()) {
            front = rear = newNode;
            rear->next = front; // 🔧 Ensure it's circular
        } else {
            rear->next = newNode;
            rear = newNode;
            rear->next = front; // Maintain circular nature
        }
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        if (front == rear) {
            delete front;
            front = rear = nullptr;
        } else {
            Node* temp = front;
            front = front->next;
            delete temp;
            rear->next = front; // 🔁 Maintain circular link
        }
    }

    int Front() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return front->data;
    }

    void printQueue() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }

        Node* temp = front;
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != front);
        cout << "FRONT" << endl;
    }
};

int main() {
    CircularQueue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.printQueue(); // Output: 10 -> 20 -> 30 -> FRONT

    q.dequeue();
    q.printQueue(); // Output: 20 -> 30 -> FRONT

    cout << "Front element is: " << q.Front() << endl; // Output: 20

    return 0;
}