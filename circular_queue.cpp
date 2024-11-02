#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;

    // Constructor to initialize a node with a name and 0 items
    Node(int val = 0): data(val), next(nullptr) {}
};

class CircularQueue {
    Node* front;
    Node* rear;

public:
    CircularQueue() {
        front = rear = nullptr;  // Initially, both front and rear are null (empty queue)
    }

    // Check if the queue is empty
    bool isEmpty() {
        return front == nullptr;
    }
    void enqueue(int val){
        Node* newNode = new Node(val);
        if(isEmpty()){
            front = rear = newNode;
        }
        else{
            rear->next = newNode;
            rear = newNode;
            rear->next = front;
        }
    }
    void dequeue(){
        if(isEmpty()){
            return;
        }
        else if(front == rear){
            delete front;
            front = rear = nullptr;
        }
        else{
            Node* temp = front;
            front = front->next;
            delete temp;
            rear->next = front;
        }
    }
    int Front(){
        if(isEmpty()){
            return -1;
        }
        return front->data;
    }
    
    void printQueue(){
        Node* temp = front;
        if(isEmpty()){
            cout << "Queue is empty" << endl;
        }
        else{
            do{
                cout << temp->data << "->";
                temp = temp->next;
            }while(temp != front);
            cout <<"Front"<< endl;
        }
    }    
};

int main() {
    CircularQueue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.printQueue(); // Expected output: 10 20 30

    q.dequeue();
    q.printQueue(); // Expected output: 20 30

    cout << "Front element is: " << q.Front() << endl; // Expected output: 20

    return 0;
}
