//Implementation of stack using array
#include<iostream>
using namespace std;

class Stack{
    int top;
    int size;
    int* arr;
    public:
    Stack(int n){
        size = n;
        top = -1;
        arr = new int[size];
    }
    ~Stack(){
        delete[] arr;
    }
    bool isEmpty(){
        return (top == -1);
    }
    bool isFull(){
        return (top == size - 1);
    }
    int Top(){
        if(isEmpty()){
            cout << "Stack is empty" << endl;
            return -1;
        }
        return arr[top];
    }
    void push(int val){
        if(isFull()){
            cout << "Stack is full" << endl;
            return ;
        }
        arr[++top] = val;
    }
    void pop(){
        if(isEmpty()){
            cout << "Stack is empty" << endl;
            return ;
        }
        top--;
    }
};

int main(){
    Stack s(5);
    s.push(10);
    s.push(20);
    cout << s.Top() << endl;
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);
    cout << s.Top() << endl;
    s.pop();
    cout << s.Top() << endl;
    return 0;
}