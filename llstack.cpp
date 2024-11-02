//Stack implementation usinf linked list
#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int val): data(val), next(nullptr){}
};

class Stack{
    public:
    Node* head;
    Stack(){
        head = nullptr;
    }
    bool isEmpty(){
        return head == nullptr;
    }
    int Top(){
        if(isEmpty()){
            cout << "Stack is empty" << " ";
            return -1;
        }
        return head->data;
    }
    void push(int val){
        Node* newNode = new Node(val);
        if(isEmpty()){
            head = newNode;
        }
        else{
            newNode->next = head;
            head = newNode;
        }
    }
    void pop(){
        if(isEmpty()){
            cout << "Stack is empty" << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }
};

int main(){
    Stack s;
    cout << s.Top() << endl;
    s.push(1);
    s.push(2);
    s.push(3);
    cout << s.Top() << endl;
    s.push(4);
    s.push(5);
    s.pop();
    cout << s.Top() << endl;
    return 0;
}